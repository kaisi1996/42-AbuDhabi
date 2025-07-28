#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default constructor of Cat is called" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type)
{
    std::cout << "Cat " << type << " is created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    this->type = other.type;
    return(*this);
}

Cat::~Cat()
{
    std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}