#ifndef CONVERT_HPP
#define CONVETR_HPP

#include <cmath>
#include <vector>
#include <iostream>

/*
Функцій конвертації "з Двійкового у Шістндацятковий"(зДВуШ) та навпаки(зШуД) - не існує. Замість цього 
використовується десятковий формат,він викорстовується у вигляді мосту між двійковим та шістнадцятковим 
форматами.
"з Двійкового у Шістнадцятковий":
ДВ -> зДВуДE -> зДEуШ
"з Шістнадцяткового у Двійковий":
Ш -> зШуДE -> зДЕуДВ
*/

// З десяткового у...
void BinaryFromDecimal(std::vector<int>& bin_array, int dec_number);
void HexadecimalFromDecimal(std::vector<int>& hex_array, int dec_number);
// З двійковго у...
void DecimalFromBinary(int& dec_number, std::vector<int> bin_array);
// З шістнадцяткового у...
void DecimalFromHexadecimal(int& dec_number, std::vector<int> hex_array);

#endif
