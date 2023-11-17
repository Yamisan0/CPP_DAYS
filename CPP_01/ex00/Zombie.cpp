#include "Zombie.hpp"

Zombie::Zombie(std::string nom):name(nom){}

Zombie::~Zombie(){
        std::cout << this->name << " has died" << std::endl;
}

void Zombie::announce(void){
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

