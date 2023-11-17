#include "Serialization.hpp"

int main(void){
    Data jk;
    Serializer obj(3);

    jk.value = 34;

    std::cout << "Original variables:" << std::endl;
    std::cout << jk.value << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(&jk);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Converted variable:" << std::endl;
    std::cout << "a: " << deserialized->value << std::endl;

     if (&jk == deserialized)
        std::cout << "Both adress are the same" << std::endl;
    else
        std::cout << "Error, differents address" << std::endl;
    return 0;


}