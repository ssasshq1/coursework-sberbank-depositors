#pragma once
#include "DepositorRepository.h"

class UserInterface {
private:
    DepositorRepository& repository;

public:
    UserInterface(DepositorRepository& repo);
    void run();
};