#include "Weapon.hpp"

class HumanB{
    std::string name;
    Weapon *_weap;
public:
    HumanB(std::string name);
    ~HumanB(void);
    void setWeapon(Weapon &weap);
    void attack();
};