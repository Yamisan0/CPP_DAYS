#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal{
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal& to_copy);
    WrongAnimal& operator=(const WrongAnimal& rhs);
    virtual ~WrongAnimal();
    void makeSound(void) const;
    std::string getType(void) const;
};


#endif