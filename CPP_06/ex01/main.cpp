#include "Serializer.hpp"

#include <iostream>

int main() {
    Data original;
    original.name = "Ada";
    original.value = 42;
    original.score = 19.5;

    Data* originalPointer = &original;
    uintptr_t raw = Serializer::serialize(originalPointer);
    Data* restoredPointer = Serializer::deserialize(raw);

    std::cout << "Original address: " << originalPointer << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Restored address: " << restoredPointer << std::endl;
    std::cout << "Pointers match: "
              << (restoredPointer == originalPointer ? "yes" : "no") << std::endl;
    std::cout << "Data: " << restoredPointer->name << ", "
              << restoredPointer->value << ", " << restoredPointer->score << std::endl;
    return restoredPointer == originalPointer ? 0 : 1;
}
