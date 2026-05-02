#pragma once
#include "Depositor.h"
#include <vector>

class DepositorRepository {
private:
    std::vector<Depositor> depositors;

public:
    void addDepositor(const Depositor& depositor);
    const std::vector<Depositor>& getAllDepositors() const;
    void setAllDepositors(const std::vector<Depositor>& newDepositors);
    
    // Добавлен метод поиска
    Depositor* findDepositor(long long accountNumber);
};