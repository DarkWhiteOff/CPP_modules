#include <iostream>
#include <string>
#include <cstdint>
#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.object1 = "object1";
    data.object2 = 2;

    // Serialize
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    // Deserialize
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;


    // Verify that the pointer matches the original
    std::cout << "Same address? " << (ptr == &data ? "Yes" : "No") << std::endl;

    // Check data integrity
    std::cout << "Data content -> object1: " << ptr->object1 << ", object2: " << ptr->object2 << std::endl;
}