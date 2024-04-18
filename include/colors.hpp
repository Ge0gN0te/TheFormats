#ifndef COLORS_HPP
#define COLORS_HPP

#include <iostream>

// Колірна "палітра" для тексту
struct CL {
	static constexpr const char* ST = "\033[0m";            // Стандартний колір терміналу
    static constexpr const char* RD = "\033[1;31m";         // Червоний
    static constexpr const char* GN = "\033[1;32m";         // Зелений
    static constexpr const char* YW = "\033[1;33m";         // Жовтий 
    static constexpr const char* BE = "\033[1;34m";         // Блакитний
};

#endif 
