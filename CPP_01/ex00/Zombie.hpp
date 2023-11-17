#include <iostream>
#include <fstream>

class Zombie{
    std::string name;
    public:
    void announce(void);
    Zombie(std::string nom);
    ~Zombie();
};

Zombie* newZombie( std::string name);
void randomChump(std::string name);