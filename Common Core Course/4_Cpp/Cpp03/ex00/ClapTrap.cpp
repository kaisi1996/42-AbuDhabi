#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) 
{
    std::cout << "Default ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &newName) : name(newName), 
                                                hitPoints(10), energyPoints(10), attackDamage(0)
{
     std::cout << "Constructor called. Welcome, ClapTrap " << name << "!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints),
                                       energyPoints(other.energyPoints), attackDamage(other.attackDamage) 
{
    *this = other;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) 
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

ClapTrap::~ClapTrap() 
{
    std::cout << "Destructor called. Goodbye, ClapTrap " << name << "!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(energyPoints > 0 || hitPoints > 0)
    {    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
        std::cout << "Not enough energy to perform an attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }
    if (hitPoints < amount)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and dies!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is out of hit points and cannot be repaired!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy points and cannot be repaired!" << std::endl;
        return;
    }

    hitPoints += amount;
    energyPoints--;

    std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
}

void	ClapTrap::displayStats() const
{
	std::cout << "ClapTrap " << name << " has " << hitPoints << " hit points, " << energyPoints << " energy points and " << attackDamage << " attack damage" << std::endl;
}
