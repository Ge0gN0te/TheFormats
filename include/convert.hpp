#ifndef CONVERT_HPP
#define CONVETR_HPP

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void BinaryFromDecimal(vector<int>& bin_array, int dec_number);
void HexadecimalFromDecimal(vector<int>& hex_array, int dec_number);
void DecimalFromBinary(int& dec_number, vector<int> bin_array);
void DecimalFromHexadecimal(int& dec_number, vector<int> hex_array);

#endif