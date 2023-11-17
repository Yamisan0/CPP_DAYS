#include "Fixed.hpp"

int Fixed::getRawBits(void)const{
    return (this->_point);
}

void Fixed::setRawBits(int const raw){
    this->_point = raw;
}

Fixed::Fixed():_point(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed_nb){
    std::cout << "Copy constructor called" << std::endl;
    this->_point = fixed_nb.getRawBits();
}

Fixed& Fixed::operator = (const Fixed &other){
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &other)
    {
        this->_point = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nb):_point(nb << _fractional){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr):_point(roundf(nbr * (1 << _fractional))){
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat()const{
    return (static_cast<float>( this->getRawBits()) / ( 1 << _fractional));
}

int Fixed::toInt()const{
    return this->_point >> _fractional;
}

std::ostream& operator << (std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return (out);
}