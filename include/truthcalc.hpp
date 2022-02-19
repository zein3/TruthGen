#ifndef _TRUTHCALC_HPP_
#define _TRUTHCALC_HPP_

#include "scanner.hpp"


/**
 * Calculate the result of a given expression.
 * Note: can't handle variables, those should be handled by permuter.
 */
class TruthCalculator {
public:
    /**
     * Calculate the result of a given expression.
     * @param exp the expression.
     * @return true or false depending on the expression.
     */
    bool calculateTruth(std::string exp);
private:
    Scanner scanner;
    std::string currentExpression;

    bool calculateExpression();
};

#endif
