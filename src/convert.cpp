#include "../include/convert.hpp"

// Перетворення десяткового формату у двійковий 
void BinaryFromDecimal(vector<int>& bin_array, int dec_number) {
    for(int i = 0; dec_number > 0; i++) {
        bin_array.push_back(dec_number % 2);
        dec_number = dec_number / 2;
    };
};
// Перетворення десяткокого формату у шістнадцятковий
void HexadecimalFromDecimal(vector<int>& hex_array, int dec_number) {
    for(int i = 0; dec_number > 0; i++) {
        hex_array.push_back(dec_number % 16);
        dec_number /= 16;
    };
};
// Перетворення двійкового формату у десятковий 
void DecimalFromBinary(int& dec_number, vector<int> bin_array) {
	int index = 0;
	dec_number = 0;	

	for(int i = 0; i <= bin_array.size() - 1; i++) {
		if(bin_array[i] == 1) {
			dec_number = dec_number + (pow(2, index));
		};
		index++;
	};
};
// Перетворення шістнадцяткового формату у десятковий
void DecimalFromHexadecimal(int& dec_number, vector<int> hex_array) {
    int index = 0;
    dec_number = 0;

    for(int i = 0; i <= hex_array.size() - 1; i++) {
        dec_number = dec_number + (hex_array[i] * (pow(16, index)));
        index++;
    };
};
