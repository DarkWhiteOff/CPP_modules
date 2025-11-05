#include <iostream>
#include <string>
#include <cstdint>
#include "Serializer.hpp"

Serializer::Serializer(void)
{
    return ;
}

Serializer::Serializer(const Serializer &copy)
{
    *this = copy;
}

Serializer &Serializer::operator=(const Serializer &src)
{
    (void) src;
    return (*this);
}

Serializer::~Serializer(void)
{
    return ;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}