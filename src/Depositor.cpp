#include "Depositor.h"
#include <iostream>
#include <iomanip> 

Depositor::Depositor(long long accNum, std::string name, std::string passport, std::string category, double initialBalance, std::string date)
    : accountNumber(accNum), fullName(name), passportData(passport), depositCategory(category), balance(initialBalance), lastOperationDate(date) {}

long long Depositor::getAccountNumber() const { return accountNumber; }
std::string Depositor::getFullName() const { return fullName; }
std::string Depositor::getPassportData() const { return passportData; }
std::string Depositor::getDepositCategory() const { return depositCategory; }
double Depositor::getBalance() const { return balance; }
std::string Depositor::getLastOperationDate() const { return lastOperationDate; }

void Depositor::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool Depositor::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true; 
    }
    return false; 
}

void Depositor::display() const {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Номер счета: " << accountNumber << std::endl;
    std::cout << "ФИО: " << fullName << std::endl;
    std::cout << "Паспорт: " << passportData << std::endl;
    std::cout << "Категория вклада: " << depositCategory << std::endl;
    std::cout << "Баланс: " << std::fixed << std::setprecision(2) << balance << " руб." << std::endl;
    std::cout << "Дата последней операции: " << lastOperationDate << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}