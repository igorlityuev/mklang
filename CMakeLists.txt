cmake_minimum_required(VERSION 3.20)


project(MKlang)

add_executable(MKlang main.cpp src/includes/lexer.hpp src/includes/lexer.cpp)
# target_include_directories(MKlang PRIVATE src/includes)