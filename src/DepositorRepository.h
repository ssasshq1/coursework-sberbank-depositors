#pragma once
#include "Depositor.h"
#include <vector>

class DepositorRepository {
private:
    std::vector<Depositor> depositors;

public:
    void addDepositor(const Depositor& depositor);
    const std::vector<Depositor>& getAllDepositors() const;
    // Метод для прямой замены всего вектора (нужен для загрузки из файла)
    void setAllDepositors(const std::vector<Depositor>& newDepositors);
};