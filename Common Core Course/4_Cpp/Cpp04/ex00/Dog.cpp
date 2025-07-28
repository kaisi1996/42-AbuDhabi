#include "Dog.hpp"


Dog::Dog() : Animal("Dog")
{
    std::cout << "Default constructor of Dog is called" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type)
{
    std::cout << "Dog " << type << " is created" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    type = other.type;
    return(*this);
}

Dog::~Dog()
{
    std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks" << std::endl;
}