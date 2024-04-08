#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <vector>

struct Maps {
    static constexpr char hex_letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
};

void TransformCharArray(std::vector<int>& int_array, std::string value);
void ArrayFromString(std::vector<int>& array, std::string value);

#endif 
