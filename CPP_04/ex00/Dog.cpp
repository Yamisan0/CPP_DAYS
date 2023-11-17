#include "Dog.hpp"

Dog::Dog():Animal("Dog"){
    std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound(void) const{
    std::cout << "BARK!" << std::endl;
}