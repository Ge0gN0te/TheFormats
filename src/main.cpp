// Імпорти сторроніх бібліотек
#include <vector>
#include <iostream>
#include <boost/program_options.hpp>
// Імпорти файлів прогрми
#include "../include/convert.hpp"
#include "../include/output.hpp"
#include "../include/data.hpp"
#include "../include/colors.hpp"

namespace po = boost::program_options;
using namespace std;


int main(int argc, char* argv[]) {
    // Описи всіх опцій
    po::options_description all_desc ("Всі існуючі опції програми");
    po::options_description func_desc ("Функції");
    po::options_description arg_desc ("Аргументи");
    po::options_description mark_desc ("Мітки");
    // Змінна для парсингу введених користувачем значень
    po::variables_map var_map;

    // Змінні для зберігання чисел і різних форматах
    int dec_number;
    vector<int> bin_array;
    vector<int> hex_array;
    // Кольорова палітра для функцій
    string color_pack[] = {CO::YELLOW, CO::GREEN, CO::RED, CO::STAND, CO::BLUE};

    // Додавання опцій та описів до них
    func_desc.add_options()
        ("help", "Вивід всіх існуючих опцій")
        ("version", "Вивід інформації про програму")
        ("convert", "Конвертування числа")
        ;
    
    arg_desc.add_options()
        ("bin", po::value<string>(), "Двійковий формат")
        ("dec", po::value<int>(&dec_number), "Десятковий формат")
        ("hex", po::value<string>(), "Шістнадцятковий формат")
        ;

    mark_desc.add_options()
        ("bm", "Мітка двійкового формату")
        ("dm", "Мітка десяткового формату")
        ("hm", "Мітка шістнадцяткового формату")
        ;

    // Групування всіх описів в один 
    all_desc.add(func_desc).add(arg_desc).add(mark_desc);

    // Блок парсингу
    try {
        // Парсинг командного рядка
        po::store(po::parse_command_line(argc, argv, all_desc), var_map);
        // Повідомлення про успішний парсинг
        po::notify(var_map);

    } catch(const po::unknown_option& e) {
        cerr << CO::RED << "Помилка: " << "Невідома опція! " << e.what() << CO::STAND << endl;
        return 0;
    } catch(const po::invalid_option_value& e) {
        cerr << CO::RED << "Помилка: " << "Значення не відповідає формату! " << e.what() << CO::STAND << endl;
        return 0;
    } catch(const po::invalid_command_line_syntax& e) {
        cerr << CO::RED << "Помилка: " << "Аргумент не заповнений! " << e.what() << CO::STAND << endl;
        return 0;
    };

    // Блок для перевірки введених опцій
    try {
        if(var_map.count("help")) {
            cout << all_desc << endl;
            OutputHelpTxt(color_pack);
        };

        if(var_map.count("version")) {
            OutputVersionTxt(color_pack);
        };

        if(var_map.count("convert")) {
    
            if(var_map.count("bin") || var_map.count("dec") || var_map.count("hex")) {

                if(var_map.count("bm") || var_map.count("dm") || var_map.count("hm")) {
                    // З десяткового формат в...
                    if(var_map.count("dec")) {

                        if(var_map.count("dm")) {
                            OutputDecimalNumber(dec_number, color_pack);
                        };

                        if(var_map.count("hm")) {
                            HexadecimalFromDecimal(hex_array, dec_number);
                            OutputHexadecimalArray(hex_array, color_pack);
                        };

                        if(var_map.count("bm")) {
                            BinaryFromDecimal(bin_array, dec_number);
                            OutputBinaryArray(bin_array, color_pack);
                        };
                
                    } else if(var_map.count("bin")) {
                        // З двійкового формату в...
                        ArrayFromString(bin_array, var_map["bin"].as<string>());

                        if(var_map.count("dm")) {
                            DecimalFromBinary(dec_number, bin_array);
                            OutputDecimalNumber(dec_number, color_pack);
                        };

                        if(var_map.count("hm")) {
                            DecimalFromBinary(dec_number, bin_array);
                            HexadecimalFromDecimal(hex_array, dec_number);
                            OutputHexadecimalArray(hex_array, color_pack);
                        };

                        if(var_map.count("bm")) {
                            OutputBinaryArray(bin_array, color_pack);
                        };

                    } else if(var_map.count("hex")) {
                        // З шістнадцяткового формату в...
                        TransformCharArray(hex_array, var_map["hex"].as<string>());

                        if(var_map.count("dm")) {
                            DecimalFromHexadecimal(dec_number, hex_array);
                            OutputDecimalNumber(dec_number, color_pack);
                        };

                        if(var_map.count("hm")) {
                        OutputHexadecimalArray(hex_array, color_pack);
                        };

                        if(var_map.count("bm")) {
                            DecimalFromHexadecimal(dec_number, hex_array);
                            BinaryFromDecimal(bin_array, dec_number);
                            OutputBinaryArray(bin_array, color_pack);
                        };
                    };

                } else {
                    throw string("Відсутні мітки для конвертування!");
                };

            } else {
                throw string("Відсутній формат числа для конвертування!");
            };
        };

        if(argc < 2) {
            throw string("Відсутні опції!");
        };

    } catch(const string e) {
        cerr << CO::RED << "Помилка: " << e << CO::STAND << endl;
    };


    return 0;
};