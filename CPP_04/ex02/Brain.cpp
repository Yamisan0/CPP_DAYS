#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain constructed" << std::endl;
}

Brain::~Brain(){
    std::cout << "Brain destructed" << std::endl;
}

Brain::Brain(const Brain& to_copy){
    *this = to_copy;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator = (const Brain& rhs){
    if (this != &rhs)
    {
        for( int i = 0; i < 100; i++)
        {
            this->ideas[i] = rhs.ideas[i];
        }
    }
    std::cout << "Brain copy assignement operator called" << std::endl;
    return (*this);
}