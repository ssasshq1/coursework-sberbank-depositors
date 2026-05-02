#include "Logger.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>

void Logger::log(const std::string& message) {
    // Открываем файл в режиме дозаписи
    std::ofstream log_file("log.txt", std::ios::app);
    if (!log_file.is_open()) {
        return; // Не удалось открыть файл лога
    }

    // Получаем текущее время
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    
    // Форматируем время в строку "ГГГГ-ММ-ДД ЧЧ:ММ:СС"
    tm local_tm;
    localtime_s(&local_tm, &time_t_now);

    // Записываем в файл
    log_file << std::put_time(&local_tm, "[%Y-%m-%d %H:%M:%S] ") << message << std::endl;
}