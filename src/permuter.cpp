#include "permuter.hpp"
#include <algorithm>


Permuter::Permuter(std::string &exp) : VariableTable(exp), expression {exp} {}

std::string Permuter::getExpression() {
    // copy to temporary variable result
    std::string result = expression;

    for (char c : getVariables()) {
        std::replace(result.begin(), result.end(), c, getVariableValue(c) ? 'T' : 'F');
    }

    return result;
}

void Permuter::permute() {
}

bool Permuter::canPermute() {
    if (getVariables().size() == 0) {
        return false;
    }

    // if there is a variable that still has the value true, then we can still permute the expression
    bool hasTrue = false;
    for (auto it = getVariables().begin(); it != getVariables().end(); it++) {
        auto val = getVariableValue(*it);
        if (val) {
            hasTrue = true;
            break;
        }
    }

    return hasTrue ? true : false;
}
