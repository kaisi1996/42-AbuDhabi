#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed{
private:
    int fixedPoint;
    static const int fractionalBits = 8;
public:
    Fixed();  // Default constructor
    Fixed(const int intNumber);
    Fixed(const float floatNumber);
    Fixed(const Fixed& copy);  // Copy constructor
    Fixed& operator=(const Fixed& copy);    // Copy assignment operator
    ~Fixed();  // Destructor
    float	toFloat(void) const;
	int		toInt(void) const;

    int getFixedPoint(void) const;

    // comparison operators
    bool operator>(const Fixed& fixed) const;
    bool operator<(const Fixed& fixed) const;
    bool operator>=(const Fixed& fixed) const;
    bool operator<=(const Fixed& fixed) const;
    bool operator==(const Fixed& fixed) const;
    bool operator!=(const Fixed& fixed) const;

    //  arithmetic operators
    Fixed operator+(const Fixed& fixed) const;
    Fixed operator-(const Fixed& fixed) const;
    Fixed operator*(const Fixed& fixed) const;
    Fixed operator/(const Fixed& fixed) const;

    // Increment and decrement operators
    Fixed& operator++();   
    Fixed operator++(int); 
    Fixed& operator--();   
    Fixed operator--(int); 

    // static member functions
	static Fixed&   min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed&   max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);

};

    std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);
	

#endif
