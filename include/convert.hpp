#ifndef CONVERT_HPP
#define CONVETR_HPP

#include <cmath>
#include <iostream>
#include <vector>

void BinaryFromDecimal(std::vector<int>& bin_array, int dec_number);
void HexadecimalFromDecimal(std::vector<int>& hex_array, int dec_number);
void DecimalFromBinary(int& dec_number, std::vector<int> bin_array);
void DecimalFromHexadecimal(int& dec_number, std::vector<int> hex_array);

#endif
