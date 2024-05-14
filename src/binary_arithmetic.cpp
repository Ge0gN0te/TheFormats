#include "../include/binary_arithmetic.hpp"
using namespace std;


int MaxSize(vector<int> first_array, vector<int> second_array) {
    /*  Визначення найбільшого вектора за розміром
        Ввід:
        * first_array - перший числовий вектор;
        * second_array - другий числовий вектор;
        Вививід:
        * max - найбільший розмір;  */
    return max(first_array.size(), second_array.size());
};

int BinaryCompare(vector<int> first_bin, vector<int> second_bin) {
    /*  Порівняння двох двійкових векторів
        Ввід:
        * first_bin - перший бінарний вектор;
        * second_bin - другий бінарний вектор;
        Вививід:
        * result - результат порівняння (-1 якщо перше число менше, 0 якщо вони рівні, 1 якщо перше число більше);  */
    // Визначаємо довжини векторів
    int size1 = first_bin.size();
    int size2 = second_bin.size();

    // Порівнюємо довжини і доповнюємо вектори нулями зліва, якщо необхідно
    if (size1 < size2) {
        first_bin.insert(first_bin.begin(), size2 - size1, 0);
    } else if (size2 < size1) {
        second_bin.insert(second_bin.begin(), size1 - size2, 0);
    };

    // Порівнюємо значення поелементно
    for (int i = 0; i < first_bin.size(); i++) {
        if (first_bin[i] < second_bin[i]) {
            return -1;
        } else if (first_bin[i] > second_bin[i]) {
            return 1;
        };
    };

    return 0; // Якщо вони рівні
};

vector<int> BinaryAddition(vector<int> first_bin, vector<int> second_bin) {
    /*  Знаходження суми двох двійкових векторів
        Ввід:
        * first_array - перший числовий вектор;
        * second_array - другий числовий вектор;
        Вививід:
        * result_bin - сума двох ввідних векторів;  */
    int sum = 0;
    int carry = 0;
    int max_size;
    vector<int> result_bin;

    max_size = MaxSize(first_bin, second_bin);

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
    /*  Знаходження різниці двох двійкових векторів
        Ввід:
        * first_array - перший числовий вектор;
        * second_array - другий числовий вектор;
        Вививід:
        * result_bin - різниця двох ввідних векторів;  */
    int diff = 0;
    int borrow = 0;
    int max_size;
    vector<int> result_bin;

    max_size = MaxSize(first_bin, second_bin);

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
    /*  Знаходження добутку двох двійкових векторів
        Ввід:
        * first_array - перший числовий вектор;
        * second_array - другий числовий вектор;
        Вививід:
        * result_bin - добуток двох ввідних векторів;  */
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


vector<int> BinaryDivision(vector<int> dividend_bin, vector<int> divisor_bin) {
    if (BinaryCompare(divisor_bin, {0}) == 0) {
        throw runtime_error("Division by zero");
    }

    vector<int> quotient_bin;
    vector<int> remainder_bin = dividend_bin;

    while (BinaryCompare(remainder_bin, divisor_bin) >= 0) {
        quotient_bin.push_back(1);
        remainder_bin = BinarySubtraction(remainder_bin, divisor_bin);
    }

    while (!quotient_bin.empty() && quotient_bin.back() == 0) {
        quotient_bin.pop_back();
    }

    if (quotient_bin.empty()) {
        return {0};
    }

    return quotient_bin;
}
