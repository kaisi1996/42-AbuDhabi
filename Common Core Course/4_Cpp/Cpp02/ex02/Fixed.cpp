#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{}

Fixed::Fixed(const int intNumber)
{
    fixedPoint = intNumber * (1 << fractionalBits);
}

Fixed::Fixed(const float floatNumber)
{
	fixedPoint = roundf(floatNumber * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& copy)
{
    fixedPoint = copy.fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if (this != &copy)
    {
        fixedPoint = copy.fixedPoint;
    }
    return (*this);
}

Fixed::~Fixed()
{}

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

bool Fixed::operator>(const Fixed& fixed) const 
{
    return fixedPoint > fixed.fixedPoint;
}

bool Fixed::operator<(const Fixed& fixed) const 
{
    return fixedPoint < fixed.fixedPoint;
}

bool Fixed::operator>=(const Fixed& fixed) const 
{
    return fixedPoint >= fixed.fixedPoint;
}

bool Fixed::operator<=(const Fixed& fixed) const 
{
    return fixedPoint <= fixed.fixedPoint;
}

bool Fixed::operator==(const Fixed& fixed) const 
{
    return fixedPoint == fixed.fixedPoint;
}

bool Fixed::operator!=(const Fixed& fixed) const 
{
    return fixedPoint != fixed.fixedPoint;
}

Fixed Fixed::operator+(const Fixed& fixed) const 
{
    Fixed result;
    result.fixedPoint = fixedPoint + fixed.fixedPoint;
    return result;
}

Fixed Fixed::operator-(const Fixed& fixed) const
{
    Fixed result;
    result.fixedPoint = fixedPoint - fixed.fixedPoint;
    return result;
}

Fixed Fixed::operator*(const Fixed& fixed) const
{
    Fixed result;
    result.fixedPoint = (fixedPoint * fixed.fixedPoint) / (1 << fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& fixed) const
{
    Fixed result;
    result.fixedPoint = (fixedPoint / fixed.fixedPoint) * (1 << fractionalBits);
    return result;
}

Fixed& Fixed::operator++() { // Pre-increment
    ++fixedPoint;
    return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
    Fixed temp(*this);
    ++fixedPoint;
    return temp;
}

Fixed& Fixed::operator--() { // Pre-decrement
    --fixedPoint;
    return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
    Fixed temp(*this);
    --fixedPoint;
    return temp;
}

Fixed&  Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getFixedPoint() < fixed2.getFixedPoint())
		return (fixed1);
	else
	 	return (fixed2);
}

const Fixed&    Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getFixedPoint() < fixed2.getFixedPoint())
		return (fixed1);
	else
	 	return (fixed2);
}

Fixed&  Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1.getFixedPoint() > fixed2.getFixedPoint())
		return (fixed1);
	else
	 	return (fixed2);
}

const Fixed&    Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1.getFixedPoint() > fixed2.getFixedPoint())
		return (fixed1);
	else
	 	return (fixed2);
}

int Fixed::getFixedPoint(void) const
{
    return(fixedPoint);
}
std::ostream&   operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}