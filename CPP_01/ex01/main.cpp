#include "Zombie.hpp"

int main()
{
    int nb = 3;
    Zombie *zomb;
    zomb = zombieHorde(nb, "Aziz");
    for (int i = 0; i < nb; i++)
    {
        zomb[i].announce();
    }
    delete[] zomb;
}