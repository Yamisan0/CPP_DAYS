#include "Animal.hpp"

Animal::Animal():_type("no_type"){
    std::cout << this->_type << " Animal constructed" << std::endl;
}

Animal::Animal(std::string type):_type(type){
    std::cout << this->_type << " Animal constructed" << std::endl;
}

Animal::Animal(const Animal& to_copy){
    *this = to_copy;
    std::cout << this->_type << " Animal constructed by copy" << std::endl;
}

Animal& Animal::operator = (const Animal& rhs){
    if ( this != &rhs)
    this->_type = rhs._type;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const{
    std::cout << "Animal Sound!" << std::endl;
}

std::string Animal::getType(void) const{
    return (this->_type);
}


