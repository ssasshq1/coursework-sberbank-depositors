#include "FileManager.h"
#include <fstream>
#include <sstream>

void FileManager::saveToFile(const std::vector<Depositor>& depositors, const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return; 
    }

    for (const auto& depositor : depositors) {
        file << depositor.getAccountNumber() << ";"
             << depositor.getFullName() << ";"
             << depositor.getPassportData() << ";"
             << depositor.getDepositCategory() << ";"
             << depositor.getBalance() << ";"
             << depositor.getLastOperationDate() << "\n";
    }
}

std::vector<Depositor> FileManager::loadFromFile(const std::string& filename) const {
    std::vector<Depositor> depositors;
    std::ifstream file(filename);
    if (!file.is_open()) {
        return depositors; 
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;

        long long accNum;
        std::string name, passport, category, date;
        double balance;

        std::getline(ss, item, ';');
        accNum = std::stoll(item);
        std::getline(ss, name, ';');
        std::getline(ss, passport, ';');
        std::getline(ss, category, ';');
        std::getline(ss, item, ';');
        balance = std::stod(item);
        std::getline(ss, date, ';');

        depositors.emplace_back(accNum, name, passport, category, balance, date);
    }

    return depositors;
}