#pragma once
#include <string>

class Logger {
public:
    // Статический метод, который можно вызывать откуда угодно, не создавая объект класса
    static void log(const std::string& message);
};