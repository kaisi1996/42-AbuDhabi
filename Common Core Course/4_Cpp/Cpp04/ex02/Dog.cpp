#include "Dog.hpp"


Dog::Dog() : Animal("Dog")
{
    std::cout << "Default constructor of Dog is called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const std::string& type) : Animal(type)
{
    std::cout << "Dog " << type << " is created" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain();
	*this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    this->type = other.type;
	*brain = *other.brain;
    return(*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog is destroyed" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog barks" << std::endl;
}