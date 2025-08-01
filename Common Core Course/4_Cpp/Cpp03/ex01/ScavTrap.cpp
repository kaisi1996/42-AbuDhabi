#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    name = "Default";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Default ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(const std::string &newName) : ClapTrap(newName)
{
	name = newName;
	hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "Constructor called. Welcome, ScavTrap " << name << "!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
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

ScavTrap::~ScavTrap() 
{
    std::cout << "Destructor called. Goodbye, ScavTrap " << name << "!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(energyPoints > 0 && hitPoints > 0)
    {    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "Not enough energy to perform an attack!" << std::endl;
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}