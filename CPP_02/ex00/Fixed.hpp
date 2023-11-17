#ifndef FIXED_H
# define FIXED_H


#include <iostream>

class Fixed{
    private:
        int point;
        static const int fractional = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &fixed_nb);
        Fixed& operator = (const Fixed &other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif