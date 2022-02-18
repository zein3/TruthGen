#include "scanner.hpp"


void Scanner::loadExpression(std::string &exp) {

}

void Scanner::advance() {
    tokenIndex = hasMoreTokens() ? (tokenIndex + 1) : tokenIndex;
}

void Scanner::goBack() {
    tokenIndex = (tokenIndex > 0) ? (tokenIndex - 1) : tokenIndex;
}

TokenType Scanner::tokenType() {

}

bool Scanner::hasMoreTokens() {
    return (tokenIndex < tokens.size() - 1);
}

bool Scanner::getValue() {

}

Operator Scanner::getOperator() {

}
