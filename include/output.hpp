#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <fstream>
#include <vector>
#include <cstdlib>

#include "colors.hpp"

void OutputBinaryArray(std::vector<int>& bin_array);
void OutputHexadecimalArray(std::vector<int>& hex_array, const char hex_map[]);
void OutputDecimalNumber(int dec_number);

void OutputVersionTxt();

#endif 
