#include <iostream>


int main() {
    std::cout << "Hello, world!" << std::endl;
    try {

    } catch (std::exception &err) {
        std::cout << "ERROR: " << err.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
