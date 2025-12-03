#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"

class Serializer
{
public :
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private :
    Serializer(void);
    Serializer(const Serializer &copy);
    Serializer &operator=(const Serializer &src);
    ~Serializer(void);
};

#endif