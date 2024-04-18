// Імпорти сторонніх бібліотек
#include <vector>
#include <iostream>
#include <boost/program_options.hpp>
#include <boost/any.hpp>
// Імпорти файлів прогрми
#include "../include/convert.hpp"
#include "../include/binary_arithmetic.hpp"
#include "../include/output.hpp"
#include "../include/data.hpp"

namespace po = boost::program_options;
using namespace std;


int main(int argc, char* argv[]) {
    // Описи всіх опцій
    po::options_description all_desc ("Всі опції програми");
    po::options_description func_desc ("Функції");
    po::options_description arg_desc ("Аргументи");
    po::options_description mark_desc ("Марки");
    // Змінна для парсингу введених користувачем значень
    po::variables_map var_map;

    // Змінні для зберігання чисел і різних форматах
    int dec_number;                 // Десяткове число
    vector<int> first_bin;          // Перший, двійковий вектор
    vector<int> second_bin;         // Другий, двійковий вектор(для арифметичних операцій)
    vector<int> result_bin;         // Третій, Двійковий вектор(для арифметичних операцій)
    vector<int> hex_array;          // Шістнадцятковий вектор

    // Додавання опцій та описів до них
    func_desc.add_options()
        ("help", "Вивести всі опції")
        ("version", "Вивести інформацію про програму")
        ("convert", "Конвертування трьох форматів")
        ("arithmetic", po::value<char>(), "Двійкова арифметика")
        ;
    arg_desc.add_options()
        ("fbin", po::value<string>(), "Перший, двійковий формат")
        ("sbin", po::value<string>(), "Другий, двійковий формат")
        ("dec", po::value<int>(&dec_number), "Десятковий формат")
        ("hex", po::value<string>(), "Шістнадцятковий формат")
        ;
    mark_desc.add_options()
        ("bm", "Марка двійкового формату")
        ("dm", "Марка десяткового формату")
        ("hm", "Марка шістнадцяткового формату")
        ;
    // Групування всіх описів в один 
    all_desc.add(func_desc).add(arg_desc).add(mark_desc);

    // Блок парсингу
    try {
        // Парсинг командного рядка
        po::store(po::parse_command_line(argc, argv, all_desc), var_map);
    } catch(const po::unknown_option& e) {
        cerr << CL::RD << "Помилка, детальніше(англ.): " << e.what() << CL::ST << endl;
        return 1;
    } catch(const po::invalid_option_value& e) {
        cerr << CL::RD << "Помилка, детальніше(англ.): " << e.what() << CL::ST << endl;
        return 1;
    } catch(const po::invalid_command_line_syntax& e) {
        cerr << CL::RD << "Помилка, детальніше(англ.): " << e.what() << CL::ST << endl;
        return 1;
    } catch(const boost::wrapexcept<po::ambiguous_option>& e) {
        cerr << CL::RD << "Помилка, детальніше(агл.): " << e.what() << CL::ST << endl;
        return 1;
    } catch(const boost::wrapexcept<boost::bad_any_cast>& e) {
        cerr << CL::RD << "Помилка, детальніше(англ.): " << e.what() << CL::ST << endl;
        return 1;
    } catch(const boost::bad_any_cast& e) {
        cerr << CL::RD << "Помилка, детальніше(англ.): " << e.what() << CL::ST << endl;
        return 1;
    };
    // Повідомлення про успішний парсинг
    po::notify(var_map);

    // Блок для перевірки введених опцій
    try {
        // --help
        if(var_map.count("help")) {
            cout << all_desc << endl;
        };

        // --version
        if(var_map.count("version")) {
            OutputVersionTxt();
        };

        // --convert
        if(var_map.count("convert")) {

            // Перевірка потрібних аргументів
            if(var_map.count("fbin") || var_map.count("sbin")|| var_map.count("dec") || var_map.count("hex")) {

                // Перевірка потрібних марок 
                if(var_map.count("bm") || var_map.count("dm") || var_map.count("hm")) {

                    // з Десяткового у...
                    if(var_map.count("dec")) {

                        // ...Двійковий
                        if(var_map.count("bm")) {
                            BinaryFromDecimal(first_bin, dec_number);
                            OutputBinaryArray(first_bin);
                        };

                        // Вивести введені дані
                        if(var_map.count("dm")) {
                            OutputDecimalNumber(dec_number);
                        };

                        // ...Шістнадцятковий
                        if(var_map.count("hm")) {
                            HexadecimalFromDecimal(hex_array, dec_number);
                            OutputHexadecimalArray(hex_array, Maps::hex_letters);
                        };

                    // З Двійкового у...
                    } else if(var_map.count("fbin") || var_map.count("sbin")) {

                        // Перетворення введених данних string -> int
                        if(var_map.count("fbin")) {
                            ArrayFromString(first_bin, var_map["fbin"].as<string>());
                        } else if(var_map.count("sbin")) {
                            ArrayFromString(first_bin, var_map["sbin"].as<string>());
                        };

                        // Вивести введені дані
                        if(var_map.count("bm")) {
                            OutputBinaryArray(first_bin);
                        };

                        // ...Десятковий
                        if(var_map.count("dm")) {
                            DecimalFromBinary(dec_number, first_bin);
                            OutputDecimalNumber(dec_number);
                        };

                        // ...Шістнадцятковий
                        if(var_map.count("hm")) {
                            // Використання "Десяткового мосту"
                            DecimalFromBinary(dec_number, first_bin);
                            HexadecimalFromDecimal(hex_array, dec_number);
                            OutputHexadecimalArray(hex_array, Maps::hex_letters);
                        };


                    // З Шістнадцяткового у...
                    } else if(var_map.count("hex")) {
                        
                        // Перетворення введених данних char -> int
                        TransformCharArray(hex_array, var_map["hex"].as<string>());

                        // ...Двійковий
                        if(var_map.count("bm")) {
                            // Використання "Десяткового мосту"
                            DecimalFromHexadecimal(dec_number, hex_array);
                            BinaryFromDecimal(first_bin, dec_number);
                            OutputBinaryArray(first_bin);
                        };
                        
                        // ...Десятковий
                        if(var_map.count("dm")) {
                            DecimalFromHexadecimal(dec_number, hex_array);
                            OutputDecimalNumber(dec_number);
                        };

                        // Вивести введені дані
                        if(var_map.count("hm")) {
                            OutputHexadecimalArray(hex_array, Maps::hex_letters);
                        };

                    };

                } else {
                    throw string("відсутні марки, для вказання вихідного формату");
                };

            } else {
                throw string("відсутній аргумент, для вказання вхідного формату");
            };

        // --arithmetic
        } else if(var_map.count("arithmetic")) {

            // Перетворення введених данних string -> int
            ArrayFromString(first_bin, var_map["fbin"].as<string>());
            ArrayFromString(second_bin, var_map["sbin"].as<string>());

            // Додавання
            if(var_map["arithmetic"].as<char>() == '+') {
                result_bin = BinaryAddition(first_bin, second_bin);
            }; 

            // Віднімання
            if(var_map["arithmetic"].as<char>() == '-') {
                result_bin = BinarySubtraction(first_bin, second_bin);
            };

            // Множення
            if(var_map["arithmetic"].as<char>() == 'x') {
                result_bin = BinaryMultiplication(first_bin, second_bin);
            };

            // Ділення - відсутнє!!!

            // Перевірка марок
            if(var_map.count("bm") || var_map.count("dm") || var_map.count("hm")) {

                // Вивести результат у Двійковому форматі
                if(var_map.count("bm")) {
                    OutputBinaryArray(result_bin);
                };

                // Вивести результат у Десятковому форматі
                if(var_map.count("dm")) {
                    DecimalFromBinary(dec_number, result_bin);
                    OutputDecimalNumber(dec_number);
                };

                // Вивести результат у шістнадцятковому форматі
                if(var_map.count("hm")) {
                    // Використання "Десяткового мосту"
                    DecimalFromBinary(dec_number, result_bin);
                    HexadecimalFromDecimal(hex_array, dec_number);
                    OutputHexadecimalArray(hex_array, Maps::hex_letters);
                };

            } else {
                OutputBinaryArray(result_bin);
            };
        };

        if(argc < 2) {
            throw string("відсутні, будь які, опції. команада '--help' виведе всі існуючі опції");
        };

    } catch(const string e) {
        cerr << CL::RD << "Помилка: " << e << CL::ST << endl;
        return 1;
    } catch(const boost::wrapexcept<boost::bad_any_cast>& e) {
        cerr << CL::RD << "Помилка, детальніше(англ.): " << e.what() << CL::ST << endl;
        return 1;
    } catch(const boost::bad_any_cast& e) {
        cerr << CL::RD << "Помилка, детальніше(англ.): " << e.what() << CL::ST << endl;
        return 1;
    };


    return 0;
};
