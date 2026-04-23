#include <iostream>
#include "DepositorRepository.h"
#include "UserInterface.h"

int main() {
    // Устанавливаем русскую локаль для корректного вывода в консоль
    setlocale(LC_ALL, "Russian");

    DepositorRepository repo;
    UserInterface ui(repo);
    ui.run();

    return 0;
}

