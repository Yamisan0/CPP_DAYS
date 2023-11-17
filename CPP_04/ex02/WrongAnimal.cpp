#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("no_type"){
    std::cout << this->_type << " WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):_type(type){
    std::cout << this->_type << " WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy){
    *this = to_copy;
    std::cout << this->_type << " WrongAnimal constructed by copy" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& rhs){
    if ( this != &rhs)
    this->_type = rhs._type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "WrongAnimal Sound!" << std::endl;
}

std::string WrongAnimal::getType(void) const{
    return (this->_type);
}