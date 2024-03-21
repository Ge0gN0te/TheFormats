#include "../../include/output.hpp"

// Виведення двійкового формату
void OutputBinaryArray(vector<int>& bin_array, string colors[]) {
    int counter = 0;
    int s_counter = 0;

    cout << colors[0] << "➤➤➤➤ Двійковий формат: " << colors[1];
    for(int i = bin_array.size() - 1; i >= 0; i--) {
        if(counter == 4) {
            cout << ' ';
            counter = 0;
        };
        cout << bin_array[i];
        counter++;
        s_counter++;
    };
    cout << colors[2] << " (" << s_counter << ")" << colors[3] << endl;
};
// Виведення шістнадцяткового формату
void OutputHexadecimalArray(vector<int>& hex_array, const char hex_map[], string colors[]) {
    int counter = 0;
    int s_counter = 0;

    cout << colors[0] << "➤➤➤➤ Шістнадцятковий формат: " << colors[1];
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
    cout << colors[2] << " (" << s_counter << ")" << colors[3] << endl;
};
// Виведення десяткового формату
void OutputDecimalNumber(int dec_number, string colors[]) {
    cout << colors[0] << "➤➤➤➤ Десятковий формат: " << colors[1];
    cout << dec_number << colors[2] << endl;
};

// Виведення застережень для команди help
void OutputHelpTxt(string colors[]) {
    string line;
    int counter = 0;
    ifstream file("../components/help_info.txt"); // Відкриття файлу для зчитування

    if (!file.is_open()) { // Перевірка, чи вдалося відкрити файл
        throw string("Не вдалося відкрити файл!");
    };

    while (getline(file, line)) { // Зчитування рядків з файлу
        if(counter > 12) {
            cout << colors[1] << line << endl;
        } else {
            cout << colors[2] << line << endl; // Виведення рядка на екран
        };
        counter++;
    };
    cout << colors[3];

    file.close(); // Закриття файлу
};
// Виведення інформації про програму
void OutputVersionTxt(string colors[]) {
    string line;
    int counter = 0;
    ifstream file("../components/version_info.txt"); // Відкриття файлу для зчитування

    if (!file.is_open()) { // Перевірка, чи вдалося відкрити файл
        throw string("Не вдалося відкрити файл!");
    };

    while (getline(file, line)) { // Зчитування рядків з файлу
        if(counter > 0) {
            cout << colors[4] << line << endl;
        } else {
            cout << colors[1] << line << endl; // Виведення рядка на екран
        };
        counter++;
    };
    cout << colors[3];

    file.close(); // Закриття файлу
}