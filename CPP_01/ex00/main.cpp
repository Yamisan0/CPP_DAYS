#include "Zombie.hpp"

int main()
{
    Zombie *zomb = newZombie("bazz");
    zomb->announce();
    randomChump("Foo");
    delete zomb;
}