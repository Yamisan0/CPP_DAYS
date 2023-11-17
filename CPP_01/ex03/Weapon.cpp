#include "Weapon.hpp"


const std::string& Weapon::getType(){
    const std::string& ref_type = this->_type;
    return (ref_type);
}

void Weapon::setType(std::string new_type){
    this->_type = new_type;
}

Weapon::Weapon(std::string type){
    this->_type = type;
}