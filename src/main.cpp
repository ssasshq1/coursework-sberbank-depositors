#include <windows.h>
#include "DepositorRepository.h"
#include "UserInterface.h"
#include "FileManager.h"
#include "Logger.h"
#include <iostream>

int main() {
    SetConsoleOutputCP(1251); 
    SetConsoleCP(1251);

    Logger::log("Программа запущена.");

    const std::string filename = "depositors.csv";
    DepositorRepository repo;
    FileManager fileManager;

    auto loadedDepositors = fileManager.loadFromFile(filename);
    repo.setAllDepositors(loadedDepositors);
    Logger::log("База данных загружена. Записей: " + std::to_string(loadedDepositors.size()));
    std::cout << "База данных загружена. Записей: " << loadedDepositors.size() << std::endl;

    UserInterface ui(repo);
    ui.run();

    fileManager.saveToFile(repo.getAllDepositors(), filename);
    Logger::log("Данные сохранены. Завершение работы.");
    std::cout << "Данные успешно сохранены в файл " << filename << std::endl;

    return 0;
}