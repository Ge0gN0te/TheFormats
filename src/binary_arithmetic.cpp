#include "../include/binary_arithmetic.hpp"
using namespace std;

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

vector<int> ReverseArray(vector<int> array) {
	vector<int> new_array;

	for(int i = array.size() - 1; i >= 0; i--) {
		new_array.push_back(array[i]);
	};

	return new_array;
};

// Знаходження суми двох бінарних масивів
vector<int> BinaryAddition(vector<int> first_bin, vector<int> second_bin) {
    int sum = 0;
    int carry = 0;
    int max_size;
    vector<int> result_bin;

    max_size = HowArraysMaxSize(first_bin, second_bin);

    for(int i = 0; i <= max_size - 1; i++) {
        sum = first_bin[i] + second_bin[i] + carry;
        result_bin.push_back(sum % 2);
        carry = sum / 2;
    };

    if(carry > 0) {
        result_bin.push_back(carry);
    };

    return result_bin;
};

vector<int> BinarySubtraction(vector<int> first_bin, vector<int> second_bin) {
    int diff = 0;
    int borrow = 0;
    int max_size;
    vector<int> result_bin;

    max_size = HowArraysMaxSize(first_bin, second_bin);

    for(int i = 0; i <= max_size - 1; i++) {
        diff = first_bin[i] - second_bin[i] - borrow;

        if(diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        };

        result_bin.push_back(diff);
    };

    return result_bin;
};

vector<int> BinaryMultiplication(vector<int> first_bin, vector<int> second_bin) {
    vector<int> temp_bin = first_bin;
    vector<int> result_bin = {0}; // Початковий результат - 0

    for (int i = 0; i < second_bin.size(); i++) {
        if (second_bin[i] == 1) {
            // Додавання temp_bin до result_bin, емулюючи множення числа на само себе
            result_bin = BinaryAddition(result_bin, temp_bin);
        };
        // Перемноження temp_bin на 10 (додавання нуля зліва)
        temp_bin.insert(temp_bin.begin(), 0);
    };

    return result_bin;
};

vector<int> BinaryDivision(vector<int> first_bin, vector<int> second_bin) {
    vector<int> one = {1};
    vector<int> quotient = {0};
    vector<int> remainder = first_bin;
    vector<int> divisor = second_bin;
	vector<int> sub_result;

	sub_result = BinarySubtraction(remainder, divisor);
	sub_result = ReverseArray(sub_result);

    while (sub_result[0] != 1) {
        remainder = BinarySubtraction(remainder, divisor);
        quotient = BinaryAddition(quotient, one);
		sub_result = BinarySubtraction(remainder, divisor);
    };
    
    return quotient;
};

vector<int> BinaryModulus(vector<int> first_bin, vector<int> second_bin) {
    vector<int> quotient = BinaryDivision(first_bin, second_bin);
    vector<int> product = BinaryMultiplication(second_bin, quotient);
    vector<int> modulus = BinarySubtraction(first_bin, product);

    return modulus;
};
/*
BinaryNumber performDivision(BinaryNumber num1, BinaryNumber num2) {
    BinaryNumber quotient = {0};
    BinaryNumber remainder = num1;
    BinaryNumber divisor = num2;
    BinaryNumber one = binaryFromDecimal(1);

    while (performSubtraction(remainder, divisor).binary[0] != 1) {
        remainder = performSubtraction(remainder, divisor);
        quotient = performAddition(quotient, one);
    }
    
    return quotient;
}

BinaryNumber performModulus(BinaryNumber num1, BinaryNumber num2) {
    BinaryNumber quotient = performDivision(num1, num2);
    BinaryNumber product = performMultiplication(num2, quotient);
    BinaryNumber modulus = performSubtraction(num1, product);
    return modulus;
}
*/
