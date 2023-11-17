#include "Cat.hpp"

Cat::Cat():Animal("Cat"){
    this->brain = new Brain();
    std::cout << "Cat constructed" << std::endl;
}

Cat::~Cat(){
    delete this->brain;
    std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound(void) const{
    std::cout << "MEOW!" << std::endl;
}