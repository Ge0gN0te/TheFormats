#include "../../include/data.hpp"

// Обернений переклад шістнадцяткового формату
void TransformCharArray(vector<int>& int_array, string value) {
    for(int i = value.size() - 1; i >= 0; i--) {
        if(value[i] == 'A') {
            int_array.push_back(10);
        } else if(value[i] == 'B') {
            int_array.push_back(11);
        } else if(value[i] == 'C') {
            int_array.push_back(12);
        } else if(value[i] == 'D') {
            int_array.push_back(13);
        } else if(value[i] == 'E') {
            int_array.push_back(14);
        } else if(value[i] == 'F') {
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