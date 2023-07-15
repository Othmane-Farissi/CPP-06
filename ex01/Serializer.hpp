#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include    <iostream>
#include <sys/_types/_uintptr_t.h>
#include <sys/types.h>

typedef struct Data
{
    int    number;
    std::string studentName;
    Data* next;
} Data;


class Serializer 
{
    private:
            Serializer();
            ~Serializer();
    public:
            static uintptr_t serialize(Data *ptr);
            static Data    *deserialize(uintptr_t raw);
};

#endif