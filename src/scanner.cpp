#include "scanner.hpp"
#include <stdexcept>


void Scanner::loadExpression(std::string &exp) {
    tokens.clear();
    tokenIndex = 0;

    tokenize(exp);
}

void Scanner::advance() {
    tokenIndex = hasMoreTokens() ? (tokenIndex + 1) : tokenIndex;
}

void Scanner::goBack() {
    tokenIndex = (tokenIndex > 0) ? (tokenIndex - 1) : tokenIndex;
}

TokenType Scanner::tokenType() {
    switch(tokens[tokenIndex]) {
        case 'T': case 'F':
            return TokenType::IMM;
        case '!': case '~':
            return TokenType::UNARYOP;
        case '^': case '&': case 'v': case '|': case '>': case '=':
            return TokenType::BINARYOP;
        case '(': case ')':
            return TokenType::SYMBOL;
        default:
            // TODO create a custom exception
            throw std::runtime_error(std::string("Unknown token: " + std::string(tokens[tokenIndex], 1)));
    }
}

bool Scanner::hasMoreTokens() {
    return (tokenIndex + 1 < tokens.size());
}

bool Scanner::getValue() {
    switch(tokens[tokenIndex]) {
        case 'T':
            return true;
        case 'F':
            return false;
        default:
            // TODO create a custom exception
            throw std::runtime_error(std::string("Expected value. Got " + std::string(tokens[tokenIndex], 1)));
    }
}

Operator Scanner::getOperator() {
    switch(tokens[tokenIndex]) {
        case '^': case '&':
            return Operator::AND;
        case 'v': case '|':
            return Operator::OR;
        case '>':
            return Operator::IF;
        case '=':
            return Operator::EQ;
        case '!': case '~':
            return Operator::NOT;
        default:
            // TODO create a custom exception
            throw std::runtime_error(std::string("Expected operator. Got " + std::string(tokens[tokenIndex], 1)));
    }
}

char Scanner::getSymbol() {
    if (tokenType() != TokenType::SYMBOL) {
        throw std::runtime_error(std::string("Expected symbol. Got " + std::string(tokens[tokenIndex], 1)));
    }
    return tokens[tokenIndex];
}

void Scanner::tokenize(std::string &exp) {
    for (auto it : exp) {
        if (!isspace(it)) {
            tokens.push_back(it);
        }
    }
}
