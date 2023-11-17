#include "Fixed.hpp"

int Fixed::getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->point);
}

void Fixed::setRawBits(int const raw){
    this->point = raw;
}

Fixed::Fixed():point(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed_nb){
    std::cout << "Copy constructor called" << std::endl;
    this->point = fixed_nb.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &other){
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->point = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
