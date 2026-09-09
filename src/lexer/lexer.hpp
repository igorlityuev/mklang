#include <string>
#include <vector>



enum TokenType{
    NUMBER,
    FLOAT,  
    PLUS,
    MINUS,
    EQUAL,
    ID
};

struct Token {
    TokenType type;
    std::string value;
};



class lexer
{
private:
    bool is_digit(char c);
    void lexer_check(std::string &line);
    std::vector<Token> token;
public:
    lexer(std::string text);
    void print_lexer();
    // ~lexer();
};