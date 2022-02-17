#ifndef _SYMBOLTABLE_HPP_
#define _SYMBOLTABLE_HPP_

#include "vartable.hpp"


/**
 * Permute variables from all true to all false and manages variable.
 *
 * Extract variables from expression and store them in variables table.
 * Initialize all variables to true, and permute through them until all
 * of the variables have the value false.
 */
class Permuter : private VariableTable {
public:
    Permuter(std::string &exp);
    std::string getExpression();
    void permute();
    bool canPermute();
private:
    std::string &expression;
};

#endif
