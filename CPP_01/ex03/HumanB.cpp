#include "HumanB.hpp"

void HumanB::attack(){
    if (this->_weap)
        std::cout << this->name << " attacks with their " << this->_weap->getType() << std::endl;
    else
        std::cout << this->name << "attacks with their hands" << std::endl;
}

HumanB::HumanB(std::string name):name(name), _weap(NULL){
    std::cout << this->name << " initialized without weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weap){
    this->_weap = &weap;
}

HumanB::~HumanB(void){
    std::cout << this->name << " died" << std::endl;
}