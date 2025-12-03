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

    // Verify adress
    std::cout << "Data address (original pointer) : " << &data << std::endl;
    std::cout << "Ptr address (serialize then deserialize pointer) : " << ptr << std::endl;

    // Check data
    std::cout << "Data content -> object1: " << ptr->object1 << ", object2: " << ptr->object2 << std::endl;
}