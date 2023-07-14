#include    "Serializer.hpp"

Serialize::Serialize() {}

Serialize::~Serialize() {}

Serialize::Serialize(const Serialize& src) {}

Serialize&  operator=(const Serialize& src) {}

uintptr_t Serialize::serialize(Data *ptr)
{
    return reinterpret_cast<uniptr_t>(ptr);
}

Data    *Serialize::uniserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}