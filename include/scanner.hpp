#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

#include <string>
#include <vector>


class Scanner {
public:
    enum TokenType {
        IMM, UNARYOP, BINARYOP
    };
    enum Operator {
        AND, OR, NOT, IF, EQ
    };

    void loadExpression(std::string exp);
    void advance();
    void goBack();
    bool hasMoreTokens();
    bool getValue();
    Operator getOperator();
private:
    size_t tokenIndex = 0;
    std::vector<char> tokens;
};

#endif
