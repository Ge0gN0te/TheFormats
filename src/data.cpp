#include "../include/data.hpp"

// Обернений переклад шістнадцяткового формату
void TransformCharArray(vector<int>& int_array, string value) {
    for(int i = value.size() - 1; i >= 0; i--) {
        if(value[i] == 'A' || value[i] == 'a') {
            int_array.push_back(10);
        } else if(value[i] == 'B' || value[i] == 'b') {
            int_array.push_back(11);
        } else if(value[i] == 'C' || value[i] == 'c') {
            int_array.push_back(12);
        } else if(value[i] == 'D' || value[i] == 'd') {
            int_array.push_back(13);
        } else if(value[i] == 'E' || value[i] == 'e') {
            int_array.push_back(14);
        } else if(value[i] == 'F' || value[i] == 'f') {
            int_array.push_back(15);
        } else {
            int_array.push_back((int)value[i] - 48);
        };
    };
};
// Розділення та перетворення речення у масив
void ArrayFromString(vector<int>& array, string value) {
    for(int i = value.size() - 1; i >= 0 ; i--) {
        array.push_back((int)value[i] - 48);
    };
};
