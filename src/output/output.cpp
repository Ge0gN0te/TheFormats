#include "../../include/output.hpp"


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

void OutputHexadecimalArray(vector<int>& hex_array, string colors[]) {
    int counter = 0;
    int s_counter = 0;
    const char hex_map[] = {'A', 'B', 'C', 'D', 'E', 'F'};

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

void OutputDecimalNumber(int dec_number, string colors[]) {
    cout << colors[0] << "➤➤➤➤ Десятковий формат: " << colors[1];
    cout << dec_number << colors[2] << endl;
};

void OutputHelpMessage(string colors[]) {
    cout << colors[2] << "◆ ДЛЯ УСПІШНОЇ КОНВЕРТАЦІЇ ЧИСЛА ПОТРІБНО ВВЕСТИ ПОТРІБНІ ОПЦІЇ;\n"
    << "◆ А САМЕ ЗАПУСК ПРОГРАМИ(./progmi), ФУНКЦІЮ КОНВЕРТАЦІЇ(--convert), ФОРМАТ ТА ЙОГО\n"
    << "┗━━━ ЧИСЛО(--bin 1010) ТА МІТКУ ФОРМАТУ(--dm);\n" 
    << "◆ ФОРМАТ ТА ЙОГО ЧИСЛО - ЦЕ ВХІДНІ ДАНІ, ФОРМАТ ПОТРІБЕН ДЛЯ ТОЧНОГО ПЕРДСТАВЛЕННЯ\n"
    << "┗━━━ ЧИЛА, ЯКЕ ЙДЕ ПІCЛЯ, ВОНО І БУДЕ КОНВЕРТУВАТИСЬ;\n"
    << "◆ МІТКА - ВИКОНУЄ ФУНКЦІЮ ВКАЗІВНИКА НА ФОРМАТ, В ЯКИЙ МИ ХОЧЕМО ПЕРЕТВОРИТИ ПОПЕРЕДНЄ\n"
    << "┗━━━ ЧИСЛО;\n" 
    << "◆ ОДНОЧАСНО МОЖНА ВИКОРИСТОВУВАТИ ТРИ МІТКИ;\n"
    << "◆ ДЛЯ ПРАВИЛЬНОГО ВВЕДЕННЯ ДЕСЯТКОВОГО ЧИСЛА, ПОТРІБНО ВИКОРИСТОВУВАТИ ТІЛЬКИ ЧИСЛА;\n"
    << "◆ ДЛЯ ПРАВИЛЬНОГО ВВЕДЕННЯ ДВІЙКОВОГО ЧИСЛА, ПОТРІБНО ВИКОРИСТОВУВАТИ ТІЛЬКИ ДВА\n"
    << "┗━━━ ЧИСЛА, 0 ТА 1;\n"
    << "◆ ДЛЯ ПРАВИЛЬНОГО ВВЕДЕННЯ ШІСТНАДЦЯТКОВОГО ЧИСЛА, ПОТРІБНО ВИКОРИСТОВУВАТИ ТІЛЬКИ\n"
    << "┗━━━ ЧИСЛА 1-9 ТА БУКВИ A-F;\n"
    << colors[3] << "Приклад правильного використання функції --convert:\n"
    << colors[1] << "◆ ./progmi --convert --bin 1010 --dm = конвертація двійкового числа 1010\n"
    << "┗━━━ у десятковий формат;\n"
    << "◆ ./progmi --convert --hex AA --dm --bm = конвертація шістнадцятковго числа AA у двійковий\n"
    << "┗━━━ та десятковий формати;\n"
    << "◆ ./progmi --convert --dec 32 --dm --bm --hm = конвертація десяткового числа 32 у двійковий\n"
    << "┗━━━ та шістнадцятковий формати, та при цьому вивести десятковий формат теж;" << colors[3] << endl;
};

void OutputVersionMessage(string colors[]) {
    cout << colors[1] << "ПРОГРАМА: " << "CONVERTER " << "ВЕРСІЇ: " << "0.1\n" << colors[4]
    << "◆ Програма була підготовлена для Лабораторних робіт N3.4-3.7 Комп'ютерної схемотехніки;\n"
    << "◆ Програма для виконання функцій конвертування чисел трьох форматів числення;\n"
    << "◆ Автор програми: Диченко Давид Олександрович;" << colors[3] << endl;
}