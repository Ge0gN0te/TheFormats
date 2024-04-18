#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <vector>
#include <cstdlib>
#include <fstream>

#include "colors.hpp"

// Кожна функція - для кожного формату
void OutputBinaryArray(std::vector<int> bin_array);
void OutputHexadecimalArray(std::vector<int> hex_array, const char hex_map[]);
void OutputDecimalNumber(int dec_number);
// Інше
void OutputVersionTxt();

#endif 
