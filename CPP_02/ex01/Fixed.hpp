#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <cmath>

class Fixed{
    private:
        int _point;
        static const int _fractional = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &fixed_nb);
        ~Fixed();
        Fixed(const int nb);
        Fixed(const float nbr);

        Fixed& operator = (const Fixed &other);
        int getRawBits(void) const;
        void setRawBits(int const raw);

        int toInt(void) const;
        float toFloat(void) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif