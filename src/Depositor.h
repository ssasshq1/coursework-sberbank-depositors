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
    // Конструктор
    Depositor(long long accNum, std::string name, std::string passport, std::string category, double initialBalance);

    // Геттеры
    long long getAccountNumber() const;
    std::string getFullName() const;
    double getBalance() const;

    // Методы
    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
};