#include "../../include/binary_arithmetic.hpp"


void HowArrayMaxSize(vector<int> first_array, vector<int> second_array, int& max_size) {
    if(first_array.size() > second_array.size()) {
        max_size = first_array.size();
    } else if(first_array.size() < second_array.size()) {
        max_size = second_array.size();
    } else {
        max_size = first_array.size();
    };
};

// Знаходження суми двох бінарних масивів
void AdditionBinary(vector<int> first_bin, vector<int> second_bin, vector<int>& result_bin) {
	int sum = 0;
	int carry = 0;
    int max_size;

	HowArrayMaxSize(first_bin, second_bin, max_size);

	for(int i = 0; i <= max_size - 1; i++) {
		if(first_bin[i] > 1) {
			sum = second_bin[i] + carry;
		} else if(second_bin[i] > 1) {
			sum = first_bin[i] + carry;
		} else {
			sum = first_bin[i] + second_bin[i] + carry;
		};

		cout << "sum: " << sum << " first: " << first_bin[i] << " second: " << second_bin[i] << endl;
		result_bin.push_back(sum % 2);
		carry = sum / 2;
	};

	if(carry > 0) {
		result_bin.push_back(carry);
	};
};

