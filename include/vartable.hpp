#ifndef _VARTABLE_HPP_
#define _VARTABLE_HPP_

#include <string>
#include <vector>
#include <map>


/**
 * Table to manage variables in an expression.
 */
class VariableTable {
public:
    /**
     * Constructor for Variable Table.
     * This will create a map with variable name as keys to some boolean values.
     * All values will be initialized to true.
     * @param exp the expression to generate the table from.
     */
    VariableTable(std::string &exp);

    /**
     * Get a list of variables stored in this table.
     * @return reference to a vector containing all variables stored.
     */
    std::vector<char> &getVariables();

    /**
     * Get the current value of a variable stored in this table.
     * @param var the variable to be accessed.
     * @return the variable value.
     */
    bool getVariableValue(char var);

    /**
     * Set the value of a variable stored in this table.
     * @param var the variable to be set.
     * @param value the value to be set to.
     * @return returns true if successful, false otherwise.
     */
    bool setVariableValue(char var, bool value);
private:
    std::map<char, bool> table;
    std::vector<char> variables;
};

#endif
