#pragma once
#include "DepositorRepository.h"

class UserInterface {
private:
    DepositorRepository& repository;
    void displayMainMenu() const;
    void handleAddDepositor();
    void handleViewAllDepositors() const;
   

public:
    UserInterface(DepositorRepository& repo);
    void run();
};