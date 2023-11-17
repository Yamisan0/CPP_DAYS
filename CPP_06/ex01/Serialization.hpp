#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <string>
#include <iostream>
#include <stdint.h>

struct Data {
    int value;
};

class Serializer {
    private:
        Serializer();

    public:
        Serializer(int val);
        Serializer(const Serializer& to_copy);
        Serializer& operator = (const Serializer& rhs);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);

        static Data* deserialize(uintptr_t raw);
};
    

#endif