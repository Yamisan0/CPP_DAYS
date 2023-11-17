#include "Zombie.hpp"

Zombie::Zombie(){}

std::string Zombie::get_name(){
        return (this->name);
}

Zombie::Zombie(std::string nom):name(nom){}


Zombie::~Zombie(){
        std::cout << this->name << " has died" << std::endl;
}

void Zombie::set_name(std::string name){
    this->name = name;
}

void Zombie::announce(void){
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

