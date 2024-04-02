// Імпорти сторроніх бібліотек
#include <vector>
#include <iostream>
#include <boost/program_options.hpp>
// Імпорти файлів прогрми
#include "../include/convert.hpp"
#include "../include/binary_arithmetic.hpp"
#include "../include/output.hpp"
#include "../include/data.hpp"
#include "../include/colors.hpp"

namespace po = boost::program_options;
using namespace std;


int main(int argc, char* argv[]) {
    // Описи всіх опцій
    po::options_description all_desc ("All options for program");
    po::options_description func_desc ("Functions");
    po::options_description arg_desc ("Arguments");
    po::options_description mark_desc ("Marks");
    // Змінна для парсингу введених користувачем значень
    po::variables_map var_map;

    // Змінні для зберігання чисел і різних форматах
    int dec_number;
    vector<int> first_bin;
    vector<int> second_bin;
    vector<int> hex_array;
    vector<int> result_bin;

    // Кольорова палітра для функцій
    string color_pack[] = {CO::YELLOW, CO::GREEN, CO::RED, CO::STAND, CO::BLUE};

    // Додавання опцій та описів до них
    func_desc.add_options()
        ("help", "Output all options")
        ("version", "Output to about program")
        ("convert", "Covert to formats")
        ("arithmetic", po::value<char>(), "Binary arithmetic")
        ;
    arg_desc.add_options()
        ("fbin", po::value<string>(), "First binary format")
        ("sbin", po::value<string>(), "Second binary format")
        ("dec", po::value<int>(&dec_number), "Decimal format")
        ("hex", po::value<string>(), "Hexadecimal format")
        ;
    mark_desc.add_options()
        ("bm", "Binary format mark")
        ("dm", "Decimal format mark")
        ("hm", "Hexadecimal format mark")
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
        cerr << CO::RED << "Error: " << "Invalid option! " << e.what() << CO::STAND << endl;
        return 0;
    } catch(const po::invalid_option_value& e) {
        cerr << CO::RED << "Error: " << "Value dose't have format " << e.what() << CO::STAND << endl;
        return 0;
    } catch(const po::invalid_command_line_syntax& e) {
        cerr << CO::RED << "Error: " << "None value for format! " << e.what() << CO::STAND << endl;
        return 0;
    };

    // Блок для перевірки введених опцій
    try {
        if(var_map.count("help")) {
            cout << all_desc << endl;
            //OutputHelpTxt(color_pack);
        }

        else if(var_map.count("version")) {
            OutputVersionTxt(color_pack);
        };

        if(var_map.count("convert")) {
    
            if(var_map.count("fbin") || var_map.count("sbin")|| var_map.count("dec") || var_map.count("hex")) {

                if(var_map.count("bm") || var_map.count("dm") || var_map.count("hm")) {
                    // З десяткового формат в...
                    if(var_map.count("dec")) {

                        if(var_map.count("dm")) {
                            OutputDecimalNumber(dec_number, color_pack);
                        };

                        if(var_map.count("hm")) {
                            HexadecimalFromDecimal(hex_array, dec_number);
                            OutputHexadecimalArray(hex_array, Maps::hex_letters, color_pack);
                        };

                        if(var_map.count("bm")) {
                            BinaryFromDecimal(first_bin, dec_number);
                            OutputBinaryArray(first_bin, color_pack);
                        };
                
                    } else if(var_map.count("fbin") || var_map.count("sbin")) {
                        // З двійкового формату в...
                        if(var_map.count("fbin")) {
                            ArrayFromString(first_bin, var_map["fbin"].as<string>());
                        } else if(var_map.count("sbin")) {
                            ArrayFromString(first_bin, var_map["sbin"].as<string>());
                        };

                        if(var_map.count("dm")) {
                            DecimalFromBinary(dec_number, first_bin);
                            OutputDecimalNumber(dec_number, color_pack);
                        };

                        if(var_map.count("hm")) {
                            DecimalFromBinary(dec_number, first_bin);
                            HexadecimalFromDecimal(hex_array, dec_number);
                            OutputHexadecimalArray(hex_array, Maps::hex_letters, color_pack);
                        };

                        if(var_map.count("bm")) {
                            OutputBinaryArray(first_bin, color_pack);
                        };

                    } else if(var_map.count("hex")) {
                        // З шістнадцяткового формату в...
                        TransformCharArray(hex_array, var_map["hex"].as<string>());

                        if(var_map.count("dm")) {
                            DecimalFromHexadecimal(dec_number, hex_array);
                            OutputDecimalNumber(dec_number, color_pack);
                        };

                        if(var_map.count("hm")) {
                            OutputHexadecimalArray(hex_array, Maps::hex_letters, color_pack);
                        };

                        if(var_map.count("bm")) {
                            DecimalFromHexadecimal(dec_number, hex_array);
                            BinaryFromDecimal(first_bin, dec_number);
                            OutputBinaryArray(first_bin, color_pack);
                        };
                    };

                } else {
                    throw string("None marks for convert!");
                };

            } else {
                throw string("None formats for convert!");
            };
        } else if(var_map.count("arithmetic")) {
            ArrayFromString(first_bin, var_map["fbin"].as<string>());
            ArrayFromString(second_bin, var_map["sbin"].as<string>());

            if(var_map["arithmetic"].as<char>() == '+') {
                result_bin = AdditionBinary(first_bin, second_bin);
            }; 
            
            if(var_map["arithmetic"].as<char>() == '-') {
                result_bin = SubtractionBinary(first_bin, second_bin);
            };
            if(var_map["arithmetic"].as<char>() == 'x') {
                result_bin = MultiplycationBinary(first_bin, second_bin);
            };

            if(var_map["arithmetic"].as<char>() == '/') {
                //....
            };

            if(var_map.count("bm") || var_map.count("dm") || var_map.count("hm")) {

                if(var_map.count("dm")) {
                    DecimalFromBinary(dec_number, result_bin);
                    OutputDecimalNumber(dec_number, color_pack);
                };

                if(var_map.count("hm")) {
                    DecimalFromBinary(dec_number, result_bin);
                    HexadecimalFromDecimal(hex_array, dec_number);
                    OutputHexadecimalArray(hex_array, Maps::hex_letters, color_pack);
                };

                if(var_map.count("bm")) {
                    OutputBinaryArray(result_bin, color_pack);
                };

            } else {
                OutputBinaryArray(result_bin, color_pack);
            };
        };

        if(argc < 2) {
            throw string("None options!");
        };

    } catch(const string e) {
        cerr << CO::RED << "Error: " << e << CO::STAND << endl;
    };


    return 0;
};
