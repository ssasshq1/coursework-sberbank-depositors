#pragma once
#include <string>

class Depositor {
private:
    long long accountNumber;
    std::string fullName;
    std::string passportData;
    std::string depositCategory;
    double balance;
    std::string lastOperationDate;

public:
    Depositor(long long accNum, std::string name, std::string passport, std::string category, double initialBalance, std::string date);

    // Геттеры
    long long getAccountNumber() const;
    std::string getFullName() const;
    std::string getPassportData() const;
    std::string getDepositCategory() const;
    double getBalance() const;
    std::string getLastOperationDate() const;

    // Методы
    void deposit(double amount);
    bool withdraw(double amount); // Будет возвращать true/false в зависимости от успеха
    void display() const;
};