#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) {}

void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie (void)
{
    std::cout << name << ": I am dieing" << std::endl;
}