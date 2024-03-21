cmake_minimum_required(VERSION 3.0)
project(Laboratory_workN3.4-3.6, VERSION 0.1)

# Знайдемо бібліотеку Boost
find_package(Boost REQUIRED COMPONENTS program_options)

# Додаємо виконуваний файл
add_executable(progmi src/main.cpp)
target_sources(progmi PRIVATE src/convert/convert.cpp src/output/output.cpp src/data/data.cpp)

target_link_libraries(progmi PRIVATE Boost::program_options)

