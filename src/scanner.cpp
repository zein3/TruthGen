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
            throw std::runtime_error("Unknown token at: " + std::string(1, tokens[tokenIndex]));
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
            throw std::runtime_error("Expected immediate value. Got: " + std::string(1, tokens[tokenIndex]));
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
            throw std::runtime_error("Expected operator. Got: " + std::string(1, tokens[tokenIndex]));
    }
}

char Scanner::getSymbol() {
    return tokens[tokenIndex];
}

void Scanner::tokenize(std::string &exp) {
    for (auto it : exp) {
        if (!isspace(it)) {
            tokens.push_back(it);
        }
    }
}
