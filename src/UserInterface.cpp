#include "UserInterface.h"
#include "Logger.h"
#include <iostream>
#include <string>
#include <limits>

UserInterface::UserInterface(DepositorRepository& repo) : repository(repo) {}

void UserInterface::displayMainMenu() const {
    std::cout << "\n--- Главное меню ---" << std::endl;
    std::cout << "1. Добавить нового вкладчика" << std::endl;
    std::cout << "2. Показать всех вкладчиков" << std::endl;
    std::cout << "3. Найти вкладчика и провести операции" << std::endl;
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
    Logger::log("Добавлен новый вкладчик. Счет: " + std::to_string(accNum));
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

void UserInterface::handleFindDepositor() {
    long long accNum;
    std::cout << "Введите номер счета для поиска: ";
    std::cin >> accNum;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Depositor* depositor = repository.findDepositor(accNum);

    if (depositor != nullptr) {
        std::cout << "Вкладчик найден:" << std::endl;
        depositor->display();
        performOperations(depositor);
    } else {
        Logger::log("Ошибка: попытка найти несуществующий счет " + std::to_string(accNum));
        std::cout << "Вкладчик с таким номером счета не найден." << std::endl;
    }
}

void UserInterface::performOperations(Depositor* depositor) {
    int choice;
    do {
        std::cout << "\n--- Меню операций со счетом " << depositor->getAccountNumber() << " ---" << std::endl;
        std::cout << "1. Пополнить счет" << std::endl;
        std::cout << "2. Снять со счета" << std::endl;
        std::cout << "0. Вернуться в главное меню" << std::endl;
        std::cout << "Выберите опцию: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        double amount;
        switch (choice) {
        case 1:
            std::cout << "Введите сумму для пополнения: ";
            std::cin >> amount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            depositor->deposit(amount);
            Logger::log("Счет " + std::to_string(depositor->getAccountNumber()) + " пополнен на " + std::to_string(amount));
            std::cout << "Счет пополнен. Новый баланс: " << depositor->getBalance() << std::endl;
            break;
        case 2:
            std::cout << "Введите сумму для снятия: ";
            std::cin >> amount;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (depositor->withdraw(amount)) {
                Logger::log("Со счета " + std::to_string(depositor->getAccountNumber()) + " снято " + std::to_string(amount));
                std::cout << "Сумма снята. Новый баланс: " << depositor->getBalance() << std::endl;
            } else {
                Logger::log("Ошибка: недостаточно средств на счете " + std::to_string(depositor->getAccountNumber()) + " для снятия " + std::to_string(amount));
                std::cout << "Недостаточно средств на счете." << std::endl;
            }
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор." << std::endl;
        }
    } while (choice != 0);
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
        // Очищаем буфер после cin >> choice, чтобы getline работал правильно в handleAddDepositor
        if (choice != 0) { // Если не выход, то скорее всего будет еще ввод
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            handleAddDepositor();
            break;
        case 2:
            handleViewAllDepositors();
            break;
        case 3:
            handleFindDepositor();
            break;
        case 0:
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);
}