#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default constructor of Cat is called" << std::endl;
    brain = new Brain();
}

Cat::Cat(const std::string& type) : Animal(type)
{
    std::cout << "Cat " << type << " is created" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain();
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    this->type = other.type;
    *brain = *other.brain;
    return(*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat is destroyed" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Cat meows" << std::endl;
}