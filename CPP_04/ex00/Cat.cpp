#include "Cat.hpp"

Cat::Cat():Animal("Cat"){
    std::cout << "Cat constructed" << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound(void) const{
    std::cout << "MEOW!" << std::endl;
}