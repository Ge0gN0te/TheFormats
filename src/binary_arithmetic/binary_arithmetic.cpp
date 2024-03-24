#include "../../include/binary_arithmetic.hpp"


int HowArraysMaxSize(vector<int> first_array, vector<int> second_array) {
	int max_size;

    if(first_array.size() > second_array.size()) {
        max_size = first_array.size();
    } else if(first_array.size() < second_array.size()) {
        max_size = second_array.size();
    } else {
        max_size = first_array.size();
    };

	return max_size;
};

// Знаходження суми двох бінарних масивів
vector<int> AdditionBinary(vector<int> first_bin, vector<int> second_bin) {
	int sum = 0;
	int carry = 0;
    int max_size;
	vector<int> result_bin;

	max_size = HowArraysMaxSize(first_bin, second_bin);

	for(int i = 0; i <= max_size - 1; i++) {
		if(first_bin[i] < 0 || first_bin[i] > 1) {
			sum = second_bin[i] + carry;
		} else if(second_bin[i] < 0 || second_bin[i] > 1) {
			sum = first_bin[i] + carry;
		} else {
			sum = first_bin[i] + second_bin[i] + carry;
		};

		result_bin.push_back(sum % 2);
		carry = sum / 2;
	};

	if(carry > 0) {
		result_bin.push_back(carry);
	};

	return result_bin;
};

vector<int> SubtractionBinary(vector<int> first_bin, vector<int> second_bin) {
	int diff = 0;
    int borrow = 0;
	int max_size;

	vector<int> result_bin;

	max_size = HowArraysMaxSize(first_bin, second_bin);

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

	return result_bin;
};

vector<int> MultiplycationBinary(vector<int> first_bin, vector<int> second_bin) {
    vector<int> temp_bin = first_bin;
    vector<int> result_bin = {0}; // Початковий результат - 0

    for (int i = 0; i < second_bin.size(); i++) {
        if (second_bin[i] == 1) {
            // Додавання temp_bin до result_bin, емулюючи множення числа на само себе
            result_bin = AdditionBinary(result_bin, temp_bin);
        }
        // Перемноження temp_bin на 10 (додавання нуля зліва)
        temp_bin.insert(temp_bin.begin(), 0);
    }

    return result_bin;
};
