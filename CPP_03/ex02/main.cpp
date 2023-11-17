#include "FragTrap.hpp"

int main(void)
{
    FragTrap slap("Aziz");
    ClapTrap drop("Marc");

    // drop = slap;
    slap.attack("Phoenix");
    slap.beRepaired(10);
    slap.takeDamage(10);
    slap.highFivesGuys();
}