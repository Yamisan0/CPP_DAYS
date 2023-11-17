#ifndef ANIMAL_HPP
# define ANIMAL_HPP


#include <iostream>
#include <string>

class Animal {
protected:
    std::string _type;

public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& to_copy);
    Animal& operator=(const Animal& rhs);
    virtual ~Animal();
    virtual void makeSound(void) const = 0;
    std::string getType(void) const;
};

#endif