#ifndef _TRUTHCALC_HPP_
#define _TRUTHCALC_HPP_

#include "scanner.hpp"


class TruthCalculator {
public:
    bool calculateTruth(std::string exp);
private:
    Scanner scanner;
    std::string currentExpression;

    bool calculateExpression();
};

#endif
