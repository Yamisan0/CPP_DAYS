#include "HumanA.hpp"

void HumanA::attack(){

    std::cout << this->name << " attacks with their " << this->_weap.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &arm):name(name), _weap(arm){}

HumanA::~HumanA(){
    std::cout << this->name << " died" << std::endl;
}