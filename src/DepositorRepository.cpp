#include "DepositorRepository.h"

void DepositorRepository::addDepositor(const Depositor& depositor) {
    depositors.push_back(depositor);
}

const std::vector<Depositor>& DepositorRepository::getAllDepositors() const {
    return depositors;
}

void DepositorRepository::setAllDepositors(const std::vector<Depositor>& newDepositors) {
    depositors = newDepositors;
}

// Добавлена реализация метода поиска
Depositor* DepositorRepository::findDepositor(long long accountNumber) {
    for (auto& depositor : depositors) {
        if (depositor.getAccountNumber() == accountNumber) {
            return &depositor;
        }
    }
    return nullptr;
}