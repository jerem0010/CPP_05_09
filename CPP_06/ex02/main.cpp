#include "functions.hpp"

#include <iostream>

int main() {
    for (int index = 0; index < 6; ++index) {
        Base* object = generate();

        std::cout << "Pointer: ";
        identify(object);
        std::cout << "Reference: ";
        identify(*object);
        delete object;
    }
    return 0;
}
