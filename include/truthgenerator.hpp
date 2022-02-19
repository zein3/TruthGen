#ifndef _TRUTHGENERATOR_HPP_
#define _TRUTHGENERATOR_HPP_

#include "permuter.hpp"
#include "truthcalc.hpp"


/**
 * Generates a truth table.
 * Orchestrate TruthCalculator and permuter to generate a truth table.
 */
class TruthGenerator {
public:
    TruthGenerator(TruthGenerator const &) = delete;
    void operator=(TruthGenerator const &) = delete;

    /**
     * Get singleton instance of this class.
     * @return singleton
     */
    static TruthGenerator& getInstance();

    /**
     * Generate a truth table from a given expression to the given output stream.
     * @return true when table is generated successfully, false otherwise.
     */
    bool generateTruthTable(std::string &expression, std::ostream &output);
private:
    TruthGenerator() {}

    TruthCalculator calculator;
};

#endif
