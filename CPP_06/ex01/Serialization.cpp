#include "Serialization.hpp"

Serializer::Serializer(){}

Serializer::Serializer(int val){
    (void)val;
}

Serializer::Serializer(const Serializer& to_copy){
    *this = to_copy;
}

Serializer& Serializer::operator = (const Serializer& rhs){
    (void)rhs;
    return (*this);
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}
