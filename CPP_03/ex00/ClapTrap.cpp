#include "ClapTrap.hpp"
/* CONSTRUCTORS */

ClapTrap::ClapTrap():_name("default"), _hit_points(10), _energy_points(10), _attack_damage(0){
	std::cout << this->_name << " has been initialized" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name), _hit_points(10), _energy_points(10), _attack_damage(0){
	std::cout << this->_name << " has been initialized" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_copy){
	*this = to_copy;
	std::cout << this->_name << " has been initialized by copy" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &to_copy){
	this->_name = to_copy._name;
	this->_attack_damage = to_copy._attack_damage;
	this->_energy_points = to_copy._energy_points;
	this->_hit_points = to_copy._hit_points;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << _name << " has been destructed" << std::endl;
}

/* FONCTIONS MEMBRES */

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points < 1)
	{
		std::cout << this->_name << " is dead!";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " damages" << std::endl;
	this->_hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points < 1)
	{
		std::cout << this->_name << " can't do anything" << std::endl;
		return ;
	}
	std::cout << "Claptrap " << this->_name << "is repairing himself" << std::endl;
	this->_hit_points += amount;
	this->_energy_points--;
}

void    ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points < 1)
	{
		std::cout << this->_name << " can't do anything" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
}