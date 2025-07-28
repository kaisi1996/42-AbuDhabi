#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap fragTrap("A");

    fragTrap.attack("Enemy");
    fragTrap.takeDamage(20);
    fragTrap.beRepaired(10);

    fragTrap.displayStats();

    fragTrap.highFivesGuys();

    return 0;
}