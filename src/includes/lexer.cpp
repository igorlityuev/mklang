#include "lexer.hpp"
#include <iostream>




lexer::lexer(std::string text){
    std::string word=""; 
    for (char i : text) {
        if (i == ' ' || i == ';') {
            if (!word.empty()) {
                lexer_check(word);
                word.clear();
            }
            continue;
        }
        word += i;
    }
}


std::string R(int t){
    switch (t)
    {
    case 0:
        return "NUMBER";
    case 1:
        return "FLOAT";
    case 2:
        return "PLUS";
    case 3:
        return "MINUS";
    case 4:
        return "EQUAL";
    case 5:
        return "ID";
    default:
        return "ERROR";
    }
}

void lexer::print_lexer(){
    for (const Token& t : token) {
        std::cout << "{" << R(t.type) << " : " << t.value << "}"  << std::endl;
    }
}


bool lexer::is_digit(char c){
    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 1;
    default:
        return 0;
    }
}



void lexer::lexer_check(std::string &line){
    if(is_digit(line[0])){
        std::string out ="";
        bool flag = 0;
        for (int i =0; i<line.length(); i++){
            if (line[i]=='.'){
                flag =1;
            }
            out+=line[i]; 
        }
        if (flag){
            token.push_back({TokenType::FLOAT, out});   
            return;
        }
        token.push_back({TokenType::NUMBER, out});
        return;
    }else if (line == "+"){
        token.push_back({TokenType::PLUS, line});
    }else if(line == "="){
        token.push_back({TokenType::EQUAL, line});
    }else if (line == "-"){
        token.push_back({TokenType::MINUS, line});
    }

}