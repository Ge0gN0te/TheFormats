#include "../include/convert.hpp"
using namespace std;

void BinaryFromDecimal(vector<int>& bin_array, int dec_number) {
    /*  Конвертація "з Десяткового у Двійковий"
        Ввід:
        * &bin_array - посилання на вектор двійковго формату;
        * dec_number - число десяткового формату;
        Вививід:
        * &bin_array - зміна данних вектора двійкового формату;  */
    for(int i = 0; dec_number > 0; i++) {
        bin_array.push_back(dec_number % 2);
        dec_number = dec_number / 2;
    };
};

void HexadecimalFromDecimal(vector<int>& hex_array, int dec_number) {
    /*  Конвертація "з Десяткового у Шістнадцятковий"
        Ввід:
        * &hex_array - посилання на вектор шістнадцяткового формату;
        * dec_number - число десяткового формату;
        Вививід:
        * &hex_array - зміна данних вектора шістнадцяткового формату;  */
    for(int i = 0; dec_number > 0; i++) {
        hex_array.push_back(dec_number % 16);
        dec_number /= 16;
    };
};

void DecimalFromBinary(int& dec_number, vector<int> bin_array) {
    /*  Конвертація "з Двійкового у Десятковий"
        Ввід:
        * &dec_number - посилання на число десяткового формату;
        * bin_array - вектор двійкового формату;
        Вививід:
        * &dec_number - зміна данних числа десяткового формату;  */
	int index = 0;
	dec_number = 0;	

	for(int i = 0; i <= bin_array.size() - 1; i++) {
		if(bin_array[i] == 1) {
			dec_number = dec_number + (pow(2, index));
		};
		index++;
	};
};

void DecimalFromHexadecimal(int& dec_number, vector<int> hex_array) {
    /*  Конвертація "з Шістнадцяткового у Десятковий"
        Ввід:
        * &dec_number - посилання на число десяткового формату;
        * hex_array - вектор двійкового формату;
        Вививід:
        * &dec_number - зміна данних числа десяткового формату;  */
    int index = 0;
    dec_number = 0;

    for(int i = 0; i <= hex_array.size() - 1; i++) {
        dec_number = dec_number + (hex_array[i] * (pow(16, index)));
        index++;
    };
};
