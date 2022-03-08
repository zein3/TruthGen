#include "truthcalc.hpp"
#include <stdexcept>
#include <iostream>


bool TruthCalculator::calculateTruth(std::string exp) {
    currentExpression = exp;
    scanner.loadExpression(currentExpression);
    bool result = calculateExpression();

    if (scanner.hasMoreTokens()) {
        throw std::runtime_error("Unused token");
    }

    return result;
}

bool TruthCalculator::calculateExpression() {
    bool returnVal;
    switch(scanner.tokenType()) {
        case TokenType::IMM:
            returnVal = scanner.getValue();
            scanner.advance();
            break;
        case TokenType::BINARYOP:
            throw std::runtime_error("Unexpected operator: " + std::string(1, scanner.getSymbol()));
        case TokenType::UNARYOP:
            scanner.advance();
            // edge case, if it is just an immediate value, immediately calculate the result
            if (scanner.tokenType() == TokenType::IMM) {
                returnVal = !scanner.getValue();
                scanner.advance();
            }
            else {
                // since there is only 1 type of unary operator, it can be deduced here
                returnVal = !calculateExpression();
            }
            break;
        case TokenType::SYMBOL:
            if (scanner.getSymbol() != '(') {
                throw std::runtime_error("Expected (. Got: " + std::string(1, scanner.getSymbol()));
            }

            scanner.advance();
            returnVal = calculateExpression();

            if (scanner.getSymbol() != ')') {
                throw std::runtime_error("Expected ). Got: " + std::string(1, scanner.getSymbol()));
            }

            scanner.advance();
            break;
    }

    // while there is binary operator
    while (scanner.tokenType() == TokenType::BINARYOP) {
        Operator op = scanner.getOperator();
        scanner.advance();
        bool tempVal = calculateExpression();

        switch(op) {
            case Operator::AND:
                returnVal &= tempVal;
                break;
            case Operator::OR:
                returnVal |= tempVal;
                break;
            case Operator::IF:
                returnVal = !(returnVal && !tempVal);
                break;
            case Operator::EQ:
                returnVal = (returnVal == tempVal);
                break;
            case Operator::NOT:
                break;
        }
    }

    return returnVal;
}
