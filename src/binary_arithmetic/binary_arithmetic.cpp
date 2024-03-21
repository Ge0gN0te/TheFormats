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

void InArray(vector<int> in_array, vector<int> with_array) {
	for(int i = 0; i <= with_array.size(); i++) {
		in_array.push_back(with_array[i]);
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

void SubtractionBinary(vector<int> first_bin, vector<int> second_bin, vector<int>& result_bin) {
	int diff = 0;
    int borrow = 0;
	int max_size;

	HowArrayMaxSize(first_bin, second_bin, max_size);

    // Цикл для перебору двох бінарних масивів
	for(int i = 0; i <= max_size - 1; i++) {
		if(first_bin[i] > 1) {
			diff = second_bin[i] - borrow;
		} else if(second_bin[i] > 1) {
			diff = first_bin[i] - borrow;
		} else {
			diff = first_bin[i] - second_bin[i] - borrow;
		};

        if(diff < 0) {
            diff += 2;
            borrow = 1;
		} else {
            borrow = 0;
		};

        result_bin.push_back(diff);
	};

    // Видалення зайвих нулів з початку результату
    if(result_bin.size() > 1) {
		for(int i = 0; result_bin[i] == 0; i++) {
        	result_bin.erase(result_bin.begin(), result_bin.begin());
		};
	};
};

void MultiplycationBinary(vector<int> first_bin, vector<int> second_bin, vector<int>& result_bin) {
	for(int i = 0; i <= first_bin.size() - 1; i++) {
    	if(second_bin[i] == 1) {
            // Заповнення тимчасового масиву, першим двійковим числом:
            // temp_array == first_structure.bin_array

        	for(int j = 0; j < first_bin.size() - 1 - i; j++) {
				cout << "j: " << j << " i: " << i << endl;
                // Додавання масиву самого на себе
            	AdditionBinary(result_bin, result_bin, result_bin);
        	};
            // Додавання тимчасового масиву до добутку
        	AdditionBinary(result_bin, result_bin, result_bin);
    	};
	};
};