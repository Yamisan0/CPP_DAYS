#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name):ClapTrap(name), FragTrap(name), ScavTrap(name){
	this->_name = name;
	this->_hit_points = 100;
	this->_attack_damage = 30;
	this->_energy_points = 50;
	this->ClapTrap::_name = name + "_clap_name";
	std::cout << "[ DiamondTrap ] " << this->_name << " has been initialized" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "[ DiamondTrap ] has been destroyed" << std::endl;
}

void DiamondTrap::whoAmI(void){
	std::cout << " I am a [ DiamondTrap ] and my name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
