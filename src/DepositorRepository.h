#pragma once
#include "Depositor.h"
#include <vector>

class DepositorRepository {
private:
    std::vector<Depositor> depositors;

public:
    void addDepositor(const Depositor& depositor);
    
};