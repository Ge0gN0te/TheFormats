cmake_minimum_required(VERSION 3.0)
project(ThreeFormats, VERSION 0.3)

# Знайдемо бібліотеку Boost
find_package(Boost REQUIRED COMPONENTS program_options)

# Додаємо виконуваний файл
add_executable(3fm src/main.cpp)
target_sources(3fm PRIVATE src/convert/convert.cpp src/output/output.cpp src/data/data.cpp src/binary_arithmetic/binary_arithmetic.cpp)

target_link_libraries(3fm PRIVATE Boost::program_options)
target_compile_options(3fm PUBLIC -g)
