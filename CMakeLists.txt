cmake_minimum_required(VERSION 3.0)
project(Laboratory_workN3.4-3.6, VERSION 0.2)

# Знайдемо бібліотеку Boost
find_package(Boost REQUIRED COMPONENTS program_options)

# Додаємо виконуваний файл
add_executable(thfm src/main.cpp)
target_sources(thfm PRIVATE src/convert/convert.cpp src/output/output.cpp src/data/data.cpp src/binary_arithmetic/binary_arithmetic.cpp)

target_link_libraries(thfm PRIVATE Boost::program_options)

