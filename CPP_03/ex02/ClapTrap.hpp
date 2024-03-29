#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>


class ClapTrap{
    protected:
        std::string     _name;
        int             _hit_points;
        int             _energy_points;
        int             _attack_damage;
        ClapTrap();

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &to_copy);
        ClapTrap& operator = (const ClapTrap &to_copy);
        ~ClapTrap();


        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};





#endif