#include "Brain.hpp"

Brain::Brain() 
{
    std::cout << "Default constructor of Brain is called" << std::endl;
}

Brain::Brain(std::string idea)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = idea;
	std::cout << "Brain is Created" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain is created by a Copy Constructor" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain is destroyed" << std::endl;
}

std::string	Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

std::string Brain::setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
	return (this->ideas[i]);
}
