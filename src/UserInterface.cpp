#include "UserInterface.h"
#include <iostream>
#include <limits> // Для очистки буфера ввода

UserInterface::UserInterface(DepositorRepository& repo) : repository(repo) {}

void UserInterface::displayMainMenu() const {
    std::cout << "\n--- Главное меню ---" << std::endl;
    std::cout << "1. Добавить нового вкладчика" << std::endl;
    std::cout << "2. Показать всех вкладчиков" << std::endl;
    // Другие пункты будут здесь
    std::cout << "0. Выход и сохранение" << std::endl;
    std::cout << "Выберите опцию: ";
}

void UserInterface::handleAddDepositor() {
    long long accNum;
    std::string name, passport, category, date;
    double balance;
    std::string input; // Вспомогательная строка для чтения всего ввода

    std::cout << "--- Добавление нового вкладчика ---" << std::endl;

    // Читаем все как строку, а потом конвертируем в число. Это надежно!
    std::cout << "Введите номер счета: ";
    std::getline(std::cin, input);
    try {
        accNum = std::stoll(input); // stoll = string to long long
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: номер счета должен быть числом." << std::endl;
        return;
    }

    std::cout << "Введите ФИО: ";
    std::getline(std::cin, name); // getline идеально подходит для строк с пробелами

    std::cout << "Введите паспортные данные: ";
    std::getline(std::cin, passport);

    std::cout << "Введите категорию вклада: ";
    std::getline(std::cin, category); // И здесь тоже

    std::cout << "Введите начальный баланс: ";
    std::getline(std::cin, input);
    try {
        balance = std::stod(input); // stod = string to double
    } catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: баланс должен быть числом." << std::endl;
        return;
    }
    
    std::cout << "Введите дату открытия (ДД.ММ.ГГГГ): ";
    std::getline(std::cin, date);

    repository.addDepositor(Depositor(accNum, name, passport, category, balance, date));
    std::cout << "Вкладчик успешно добавлен!" << std::endl;
}

void UserInterface::handleViewAllDepositors() const {
    const auto& depositors = repository.getAllDepositors();
    if (depositors.empty()) {
        std::cout << "Список вкладчиков пуст." << std::endl;
        return;
    }
    std::cout << "\n--- Список всех вкладчиков ---" << std::endl;
    for (const auto& depositor : depositors) {
        depositor.display();
    }
}

void UserInterface::run() {
    int choice = -1;
    std::string input;

    while (choice != 0) {
        displayMainMenu();
        std::getline(std::cin, input); 

        try {
            choice = std::stoi(input); 
        } catch (const std::invalid_argument& e) {
            std::cout << "Ошибка: введите число." << std::endl;
            choice = -1; 
        }

        switch (choice) {
        case 1:
            handleAddDepositor();
            break;
        case 2:
            handleViewAllDepositors();
            break;
        case 0:
            std::cout << "Сохранение данных и выход..." << std::endl;
            break; // Выходим из цикла
        default:
            if(choice != -1) std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    }
}