#ifndef _TRUTHGENERATOR_HPP_
#define _TRUTHGENERATOR_HPP_

#include "permuter.hpp"
#include "truthcalc.hpp"


class TruthGenerator {
public:
    TruthGenerator(TruthGenerator const &) = delete;
    void operator=(TruthGenerator const &) = delete;

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
