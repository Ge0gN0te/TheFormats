#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <iostream>

// Збереження необхідних символів
struct Maps {
    static constexpr char hex_letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};       // Шістнадцяткова "абетка"
};

// Функції, зв'язані зі зміною даних векторів
void TransformCharArray(std::vector<int>& int_array, std::string value);
void ArrayFromString(std::vector<int>& array, std::string value);

#endif 
