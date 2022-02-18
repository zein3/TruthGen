#include <iostream>


int main() {
    std::cout << "Hello, world!" << std::endl;
    try {

    } catch (std::exception &err) {
        std::cout << "Oops! something went wrong." << std::endl;
        std::cerr << "ERROR: " << err.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
