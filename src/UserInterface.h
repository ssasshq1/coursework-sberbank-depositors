#pragma once
#include "DepositorRepository.h"

class UserInterface {
private:
    DepositorRepository& repository;
    void displayMainMenu() const;
    void handleAddDepositor();
    void handleViewAllDepositors() const;
    
    // Добавлены новые приватные методы
    void handleFindDepositor();
    void performOperations(Depositor* depositor);

public:
    UserInterface(DepositorRepository& repo);
    void run();
};