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
    /**
     * Constructor.
     * @param exp reference to expression to be permuted
     */
    Permuter(std::string &exp);

    /**
     * Get the expression with all the variables replaced with true or false value.
     * @return expression that can be processed by scanner.
     */
    std::string getExpression();

    /**
     * 'Permute' the expression.
     */
    void permute();

    /**
     * Checks whether the expression can be 'permuted'.
     * If all the variables are false then the expression can no longer be 'permuted'.
     * @return whether the expression can be permuted or not.
     */
    bool canPermute();
private:
    std::string &expression;
};

#endif
