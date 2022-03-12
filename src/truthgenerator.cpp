#include "truthgenerator.hpp"
#include <iostream>
#include <sstream>


TruthGenerator& TruthGenerator::getInstance() {
    static TruthGenerator instance;

    return instance;
}

bool TruthGenerator::generateTruthTable(std::string &exp, std::ostream &output) {
    std::ostringstream out;
    Permuter permuter(exp);

    // generate table header
    for (auto var : permuter.getVariables()) {
        out << var << " | ";
    }
    out << exp << std::endl;


    while (true) {
        // generate current permutation's variables' values
        for (auto var : permuter.getVariables()) {
            out << (permuter.getVariableValue(var) ? 'T' : 'F') << " | ";
        }

        // generate current permutation's result
        try {
            out << (calculator.calculateTruth(permuter.getExpression()) ? 'T' : 'F') << std::endl;
        } catch (std::exception &err) {
            std::cout << "Oops! something went wrong." << std::endl;
            std::cerr << "ERROR! " << err.what() << std::endl;
            return false;
        }

        if (permuter.canPermute()) {
            permuter.permute();
        } else {
            break;
        }
    }

    // write to output
    output << out.str();
    return true;
}
