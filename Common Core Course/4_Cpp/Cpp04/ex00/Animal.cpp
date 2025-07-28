#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Default constructor of Animal is called" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
    std::cout << "Animal " << type << " is created" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    type = other.type;
    return(*this);
}

Animal::~Animal()
{
    std::cout << "Animal " << type << " is destroyed" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "animal make sound" << std::endl;
}
