#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <vector>

using namespace std;

struct Maps {
    static constexpr char hex_letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
};

void TransformCharArray(vector<int>& int_array, string value);
void ArrayFromString(vector<int>& array, string value);

#endif 