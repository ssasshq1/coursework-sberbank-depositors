#include "Depositor.h"
#include <iostream>

Depositor::Depositor(long long accNum, std::string name, std::string passport, std::string category, double initialBalance) {
    // Реализацию добавим позже
}

long long Depositor::getAccountNumber() const { return 0; } // Заглушка
std::string Depositor::getFullName() const { return ""; } // Заглушка
double Depositor::getBalance() const { return 0.0; } // Заглушка

void Depositor::deposit(double amount) {}
void Depositor::withdraw(double amount) {}
void Depositor::display() const {}