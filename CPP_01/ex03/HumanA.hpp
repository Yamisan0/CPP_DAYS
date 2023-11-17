#include "Weapon.hpp"

class HumanA{
    std::string name;
    Weapon &_weap;
    public:
    HumanA(std::string name, Weapon &arm);
    ~HumanA();
    void attack();
};