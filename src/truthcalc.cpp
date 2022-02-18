#include "truthcalc.hpp"
#include <stdexcept>


bool TruthCalculator::calculateTruth(std::string exp) {
    currentExpression = exp;
    scanner.loadExpression(currentExpression);
    return calculateExpression();
}

bool TruthCalculator::calculateExpression() {
    bool returnVal;
    switch(scanner.tokenType()) {
        case TokenType::IMM:
            returnVal = scanner.getValue();
            scanner.advance();
            break;
        case TokenType::BINARYOP:
            // TODO create custom exception
            throw std::runtime_error("Unexpected operator");
        case TokenType::UNARYOP:
            scanner.advance();
            // since there is only 1 type of unary operator, it can be deduced here
            returnVal = !calculateExpression();
            break;
        case TokenType::SYMBOL:
            // TODO create custom exception
            if (scanner.getSymbol() != '(') {
                throw std::runtime_error("Expected (");
            }

            scanner.advance();
            returnVal = calculateExpression();

            if (scanner.getSymbol() != ')') {
                throw std::runtime_error("Expected )");
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
