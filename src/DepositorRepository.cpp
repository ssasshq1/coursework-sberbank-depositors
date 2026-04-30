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