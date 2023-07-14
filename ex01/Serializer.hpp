#ifndef SERIALIZER_HPP
#define SERRIALZER_HPP

#include    <iostream>
#include <stdint.h> 

typedef struct Data
{
    std::string studentName;
    int         number;
    Data    *next;
} Data;


class Serialize 
{
    private:
            Serialize();
            Serialize(const Serialize& src);
            Serialize& operator=(const Serialize& src);
            ~Serialize();
            uniptr_t serialize(Data *ptr);
            Data    *uniserialize(uniptr_t raw);
};

#endif