#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
    std::cout << "Default constructor called\n";
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


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return(fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    fixedPoint = raw;
}