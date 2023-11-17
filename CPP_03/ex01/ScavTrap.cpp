#include "ScavTrap.hpp"



ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_attack_damage = 20;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << this->_name << " has been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (this->_energy_points < 1)
	{
		std::cout << this->_name << " can't do anything" << std::endl;
		return ;
	}
	std::cout << "Scavtrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << this->_name << " is now in guard mod" << std::endl;
}