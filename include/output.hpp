#ifndef OUTPUT_HPP
#define OUTPUT_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

void OutputBinaryArray(std::vector<int>& bin_array, std::string colors[]);
void OutputHexadecimalArray(std::vector<int>& hex_array, const char hex_map[], std::string colors[]);
void OutputDecimalNumber(int dec_number, std::string colors[]);

//void OutputHelpTxt(std::string colors[]);
void OutputVersionTxt(std::string colors[]);

#endif 
