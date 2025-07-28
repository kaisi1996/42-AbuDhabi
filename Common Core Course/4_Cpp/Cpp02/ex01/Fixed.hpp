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

};

    std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);


#endif