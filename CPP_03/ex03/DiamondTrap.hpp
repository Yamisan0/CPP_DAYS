#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap:public FragTrap, public ScavTrap{
    private:
        std::string _name;
        DiamondTrap();
    public:
        DiamondTrap(std::string name);
        ~DiamondTrap();
        using ScavTrap::attack;
        void whoAmI(void);
};

#endif