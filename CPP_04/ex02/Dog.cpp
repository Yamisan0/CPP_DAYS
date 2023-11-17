#include "Dog.hpp"

Dog::Dog():Animal("Dog"){
    this->brain = new Brain();
    std::cout << "Dog constructed" << std::endl;
}

Dog::~Dog(){
    delete this->brain;
    std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound(void) const{
    std::cout << "BARK!" << std::endl;
}