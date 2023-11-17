#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name):ClapTrap(name){
    this->_hit_points = 100;
    this->_energy_points = 100;
    this->_attack_damage = 30;
    std::cout << "| FragTrap | " << this->_name << " has been initialized" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "| FragTrap | " << this->_name << " has been destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void){
    if (this->_energy_points < 1)
    {
        std::cout << "| FragTrap | " << this->_name << " has 0 energy points" << std::endl;
        return ;
    }
    std::cout << "| FragTrap | " << this->_name << " high fives everybody!" << std::endl;
    this->_energy_points--;
}