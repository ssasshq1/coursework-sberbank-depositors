#include "UserInterface.h"
#include <iostream>

UserInterface::UserInterface(DepositorRepository& repo) : repository(repo) {}

void UserInterface::run() {
    std::cout << "Menu will be here..." << std::endl;
}