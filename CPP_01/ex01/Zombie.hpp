#include <iostream>
#include <fstream>

class Zombie{
    std::string name;
    public:
    void announce(void);
    Zombie();
    Zombie(std::string nom);
    ~Zombie();
    std::string get_name();
    void set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);