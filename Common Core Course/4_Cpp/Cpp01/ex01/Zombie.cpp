#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) {}

Zombie::Zombie(void) {
    name = "";
}

void Zombie::setName(std::string zombieName)
{
    name = zombieName;
}
void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie (void)
{
    std::cout << name << ": is destroyed!" << std::endl;
}
