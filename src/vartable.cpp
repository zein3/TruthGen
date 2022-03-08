#include "vartable.hpp"


VariableTable::VariableTable(std::string &exp) {
    for (auto c : exp) {
        if (isalpha(c) && c != 'T' && c != 'F' && c != 'v' &&  table.count(c) == 0) {
            table.insert( std::pair<char, bool>(c, true) );
            variables.push_back(c);
        }
    }
}

std::vector<char> &VariableTable::getVariables() {
    return variables;
}

bool VariableTable::getVariableValue(char var) {
    auto result = table.find(var);
    if (result != table.end()) {
        return result->second;
    } else {
        return false;
    }
}

bool VariableTable::setVariableValue(char var, bool value) {
    auto result = table.find(var);
    if (result != table.end()) {
        result->second = value;
        return true;
    }
    else {
        return false;
    }
}
