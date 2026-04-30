#pragma once
#include "Depositor.h"
#include <vector>
#include <string>

class FileManager {
public:
    void saveToFile(const std::vector<Depositor>& depositors, const std::string& filename) const;
    std::vector<Depositor> loadFromFile(const std::string& filename) const;
};