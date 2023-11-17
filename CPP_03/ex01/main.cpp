#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap slap("Aziz");

    slap.attack("Phoenix");
    slap.guardGate();
    slap.beRepaired(10);
    slap.takeDamage(10);
}