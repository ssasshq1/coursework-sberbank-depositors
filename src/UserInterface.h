#pragma once
#include "DepositorRepository.h"

class UserInterface {
private:
    DepositorRepository& repository;
    void displayMainMenu() const;
    void handleAddDepositor();
    void handleViewAllDepositors() const;
    // Другие обработчики добавим позже

public:
    UserInterface(DepositorRepository& repo);
    void run();
};