#include "../include/data.hpp"
using namespace std;

void TransformCharArray(vector<int>& int_array, string value) {
    /*  Обернений переклад шістнадцяткового формату
        Ввід:
        * &int_array - посилання на числовий вектор;
        * value - ймовірна, буква шістнадцятковго формату;
        Вививід:
        * &int_array - зміна числового вектору;  */
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

void ArrayFromString(vector<int>& array, string value) {
    /*  Розділення та перетворення, речення у вектор
        Ввід:
        * &array - посилання на вектор, очікує перетворений масив;
        * value - речення, для перетворення;
        Вививід:
        * &array - зміна числового вектора;  */
    for(int i = value.size() - 1; i >= 0 ; i--) {
        array.push_back((int)value[i] - 48);
    };
};
