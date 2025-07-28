#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int intNumber)
{
    std::cout << "Int constructor called\n";
    fixedPoint = intNumber * (1 << fractionalBits);
}

Fixed::Fixed(const float floatNumber)
{
    std::cout << "Float constructor called\n";
	fixedPoint = roundf(floatNumber * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called\n";
    fixedPoint = copy.fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &copy)
    {
        fixedPoint = copy.fixedPoint;
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

float	Fixed::toFloat(void) const
{
	float	floatValue;

	floatValue = fixedPoint * 1.0 / (1 << fractionalBits);
	return (floatValue);
}

int		Fixed::toInt(void) const
{
    int   intValue;

    intValue = fixedPoint / (1 << fractionalBits);
    return (intValue);
}

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}