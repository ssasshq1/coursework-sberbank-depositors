#include "UserInterface.h"
#include <iostream>
#include <string>
#include <limits>

UserInterface::UserInterface(DepositorRepository& repo) : repository(repo) {}

void UserInterface::displayMainMenu() const {
    std::cout << "\n--- Главное меню ---" << std::endl;
    std::cout << "1. Добавить нового вкладчика" << std::endl;
    std::cout << "2. Показать всех вкладчиков" << std::endl;
    std::cout << "0. Выход и сохранение" << std::endl;
    std::cout << "Выберите опцию: ";
}

void UserInterface::handleAddDepositor() {
    long long accNum;
    std::string name, passport, category, date;
    double balance;

    std::cout << "--- Добавление нового вкладчика ---" << std::endl;
    std::cout << "Введите номер счета: ";
    std::cin >> accNum;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    std::cout << "Введите ФИО: ";
    std::getline(std::cin, name);

    std::cout << "Введите паспортные данные: ";
    std::getline(std::cin, passport);

    std::cout << "Введите категорию вклада: ";
    std::getline(std::cin, category);

    std::cout << "Введите начальный баланс: ";
    std::cin >> balance;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
             std::cout << "Ошибка: введите число." << std::endl;
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             choice = -1; 
             continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            handleAddDepositor();
            break;
        case 2:
            handleViewAllDepositors();
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);
}