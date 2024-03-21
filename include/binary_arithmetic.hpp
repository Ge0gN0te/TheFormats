#ifndef BINARY_ARITHMETIC_HPP
#define BINARY_ARITHMETIC_HPP

#include <iostream>
#include <vector>

using namespace std;

// Знаходження суми двох бінарних масивів
void HowArrayMaxSize(vector<int> first_array, vector<int> second_array, int& max_size);
void InArray(vector<int> in_array, vector<int> with_array);
void AdditionBinary(vector<int> first_bin, vector<int> second_bin, vector<int>& result_bin);
void SubtractionBinary(vector<int> first_bin, vector<int> second_bin, vector<int>& result_bin);
void MultiplycationBinary(vector<int> first_bin, vector<int> second_bin, vector<int>& result_bin);

#endif 