#include <windows.h> 
#include "DepositorRepository.h"
#include "UserInterface.h"
#include "FileManager.h"
#include <iostream>

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    setvbuf(stdout, nullptr, _IOFBF, 1000);


    const std::string filename = "depositors.csv";
    DepositorRepository repo;
    FileManager fileManager;

    // 1. Загружаем данные из файла в репозиторий при старте
    auto loadedDepositors = fileManager.loadFromFile(filename);
    repo.setAllDepositors(loadedDepositors);
    std::cout << "База данных загружена. Записей: " << loadedDepositors.size() << std::endl;

    // 2. Запускаем интерфейс
    UserInterface ui(repo);
    ui.run();

    // 3. Сохраняем данные из репозитория в файл перед выходом
    fileManager.saveToFile(repo.getAllDepositors(), filename);
    std::cout << "Данные успешно сохранены в файл " << filename << std::endl;

    return 0;
}