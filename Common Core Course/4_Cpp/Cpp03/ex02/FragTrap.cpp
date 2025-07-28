#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    name = "Default";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Default FragTrap is created" << std::endl;
}

FragTrap::FragTrap(const std::string &newName) : ClapTrap(newName)
{
	name = newName;
	hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Constructor called. Welcome, FragTrap " << name << "!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
    if (this != &other) 
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this; 
}

FragTrap::~FragTrap() 
{
    std::cout << "Destructor called. Goodbye, FragTrap " << name << "!" << std::endl;
}

void FragTrap::highFivesGuys() 
{
    std::cout << "Positive high fives request! (FragTrap " << name << " is requesting a high five!)" << std::endl;
}
