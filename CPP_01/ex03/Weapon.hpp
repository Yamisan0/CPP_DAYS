#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>

class Weapon{
    std::string _type;
    public:
    Weapon(std::string type);
    ~Weapon(void){}
    const std::string& getType();
    void setType(std::string new_type);
};
#endif