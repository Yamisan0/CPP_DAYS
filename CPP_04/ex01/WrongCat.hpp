#ifndef WCAT_HPP
#define CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    ~WrongCat();
    void makeSound(void) const;
};

#endif