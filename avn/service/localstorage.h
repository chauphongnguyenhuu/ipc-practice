#pragma once

#include <vector>

namespace core { struct Employee; }

std::vector<core::Employee> loadData(const char* filePath);
void saveData(const char* filePath, const std::vector<core::Employee>& data);
