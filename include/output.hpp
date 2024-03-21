#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void OutputBinaryArray(vector<int>& bin_array, string colors[]);
void OutputHexadecimalArray(vector<int>& hex_array, string colors[]);
void OutputDecimalNumber(int dec_number, string colors[]);

void OutputHelpMessage(string colors[]);
void OutputVersionMessage(string colors[]);

#endif 