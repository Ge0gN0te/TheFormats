#include "../include/output.hpp"
using namespace std;

// Виведення двійкового формату
void OutputBinaryArray(vector<int>& bin_array) {
    int counter = 0;
    int s_counter = 0;

    cout << CL::YW << "➤➤➤➤ Binary format: " << CL::GN;
    for(int i = bin_array.size() - 1; i >= 0; i--) {
        if(counter == 4) {
            cout << ' ';
            counter = 0;
        };
        cout << bin_array[i];
        counter++;
        s_counter++;
    };
    cout << CL::RD << " (" << s_counter << ")" << CL::ST << endl;
};
// Виведення шістнадцяткового формату
void OutputHexadecimalArray(vector<int>& hex_array, const char hex_map[]) {
    int counter = 0;
    int s_counter = 0;

    cout << CL::YW << "➤➤➤➤ Hexadecimal format: " << CL::GN;
    for(int i = hex_array.size() - 1; i >= 0; i--) {
        if(counter == 2) {
            cout << ' ';
            counter = 0;
        };
        if(hex_array[i] <= 9) {
            cout << hex_array[i];
        } else {
            cout << hex_map[hex_array[i] - 10];
        };
        counter++;
        s_counter++;
    };
    cout << CL::RD << " (" << s_counter << ")" << CL::ST << endl;
};
// Виведення десяткового формату
void OutputDecimalNumber(int dec_number) {
    cout << CL::YW << "➤➤➤➤ Decimal format: " << CL::GN;
    cout << dec_number << CL::ST << endl;
};
// Виведення інформації про програму
void OutputVersionTxt() {
    string line;
    int counter = 0;
    ifstream file("../data/version_info.txt"); // Відкриття файлу для зчитування

    if (!file.is_open()) { // Перевірка, чи вдалося відкрити файл
        throw string("Can't find file!");
    };
    
    while (getline(file, line)) { // Зчитування рядків з файлу
        if(counter < 4) {
            cout << CL::BE << line << endl;
        } else if(counter < 8) {
            cout << CL::YW << line << endl;
        } else {
            cout << CL::GN << line << endl;
        }
        counter++;
    };
    cout << CL::ST;

    file.close(); // Закриття файлу
};
