#include "truthgenerator.hpp"
#include <iostream>


void loop() {
    std::string input;
    while(true) {
        std::cout << ">>> ";
        std::cin >> input;

        if (input == "quit" || input == "exit") {
            break;
        }

        bool result = TruthGenerator::getInstance().generateTruthTable(input, std::cout);
        if (!result) {
            std::cout << "Encountered an error! press 'exit' or 'quit' to quit" << std::endl;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        loop();
        return EXIT_SUCCESS;
    }

    std::string input (argv[1]);
    bool result = TruthGenerator::getInstance().generateTruthTable(input, std::cout);
    return (result) ? EXIT_SUCCESS : EXIT_FAILURE;
}
