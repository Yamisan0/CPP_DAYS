#ifndef FIXED_HPP
# define FIXED_HPP


#include <iostream>
#include <cmath>

class Fixed{
	private:
		int 			_point;
		static const int _fractional = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &fixed_nb);
		~Fixed();
		Fixed(const int nb);
		Fixed(const float nbr);

		Fixed&			operator = (const Fixed &other);
		int				getRawBits(void) const;
		void			setRawBits(int const raw);

		int 			toInt(void) const;
		float 			toFloat(void) const;

		//overloads
		bool        	operator <(const Fixed& right)const;
		bool        	operator >(const Fixed& right)const;
		bool        	operator >=(const Fixed& right)const;
		bool        	operator <=(const Fixed& right)const;
		bool        	operator ==(const Fixed& right)const;
		bool        	operator !=(const Fixed& right)const;
		Fixed       	operator +(const Fixed& right)const;
		Fixed       	operator -(const Fixed& right)const;
		Fixed       	operator *(const Fixed& right)const;
		Fixed       	operator /(const Fixed& right)const;
		Fixed&       	operator ++(void);
		Fixed&      	operator --(void);
		Fixed   	   	operator ++(int);
		Fixed	     	operator --(int);

		//static members functions
		Fixed& max(Fixed& a, Fixed& b);
		Fixed& min(Fixed& a, Fixed& b);
		static const	Fixed& max(const Fixed& a, const Fixed& b);
		static const	Fixed& min(const Fixed& a, const Fixed& b);
};

std::ostream& operator << (std::ostream &out, const Fixed &obj);

#endif