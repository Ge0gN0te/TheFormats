# Реєстрування версії CMake
cmake_minimum_required(VERSION 3.0)
# Назва та версія проєкту
project(ThreeFormats, VERSION 0.3)

# Назначення компілтяора GNU GCC(G++)
set(CMAKE_CXX_COMPILER "g++")

# Пошук бібліотеки Boost
find_package(Boost 1.74.0 REQUIRED COMPONENTS program_options)
# Реєстрація бібліотеки Boost 
include_directories(${Boost_INCLUDE_DIRS})

# Додавання основного файлу
add_executable(3fm src/main.cpp)
# Додавання другорядних файлів
target_sources(3fm PRIVATE src/convert.cpp src/output.cpp src/data.cpp src/binary_arithmetic.cpp)

# Додавання бібліотеки Boost до проєкту
target_link_libraries(3fm Boost::program_options)

# 
target_compile_options(3fm PUBLIC -g)
