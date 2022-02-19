#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

#include <string>
#include <vector>


enum class TokenType {
    IMM, UNARYOP, BINARYOP, SYMBOL
};

enum class Operator {
    AND, OR, NOT, IF, EQ
};


/**
 * Parse expression.
 */
class Scanner {
public:
    /**
     * Reset tokens and load new expression.
     * @param exp expression to be loaded.
     */
    void loadExpression(std::string &exp);

    /**
     * Advance to the next token.
     */
    void advance();

    /**
     * Go back to the previous token.
     */
    void goBack();

    /**
     * Get current token's type.
     * @return current token's type.
     */
    TokenType tokenType();

    /**
     * Check if there is more token to be evaluated.
     * @return whether there is more tokens after the current token.
     */
    bool hasMoreTokens();

    /**
     * Get the immediate value of the current token.
     * @return immediate value.
     */
    bool getValue();

    /**
     * Get the type of operator of the current token.
     * @return type of operator.
     */
    Operator getOperator();

    /**
     * Get symbol for the current token.
     * @return symbol.
     */
    char getSymbol();
private:
    size_t tokenIndex = 0;
    std::vector<char> tokens;

    void tokenize(std::string &exp);
};

#endif
