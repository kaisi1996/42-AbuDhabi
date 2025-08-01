#include "ClapTrap.hpp"

// Hit Points (means health)

int main()
{
    ClapTrap clapTrap("A");
    clapTrap.attack("Enemy");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(4);
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(5);
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);
    clapTrap.beRepaired(5);
    clapTrap.beRepaired(5);
	
    clapTrap.displayStats();


    return 0;
}