#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


#include "src/includes/lexer.hpp"


int main(int argc, char *argv[]){

    if (argc <= 1){
        std::cerr<<"Error\n";
    }


    std::string file;
    for (int i =1; argc>i;i++ ){
        file+=argv[i];
    }

    std::fstream File(file);
    std::stringstream buffer;
    buffer << File.rdbuf();
    std::string text = buffer.str();

    lexer l = lexer(text);
    l.print_lexer();


    return 0;
}