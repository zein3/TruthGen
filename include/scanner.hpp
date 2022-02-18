#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

#include <string>
#include <vector>


enum class TokenType {
    IMM, UNARYOP, BINARYOP
};

enum class Operator {
    AND, OR, NOT, IF, EQ
};


class Scanner {
public:
    void loadExpression(std::string &exp);
    void advance();
    void goBack();
    TokenType tokenType();
    bool hasMoreTokens();
    bool getValue();
    Operator getOperator();
private:
    size_t tokenIndex = 0;
    std::vector<char> tokens;

    void tokenize(std::string &exp);
};

#endif
