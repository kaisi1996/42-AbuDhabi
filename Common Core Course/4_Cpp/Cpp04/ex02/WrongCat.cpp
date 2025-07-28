#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal ("WrongCat")
{
    std::cout << "Default constructor of WrongCat is called" << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type)
{
    std::cout << "WrongCat " << type << " is created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal (other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    type = other.type;
    return(*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat is destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat meows" << std::endl;
}