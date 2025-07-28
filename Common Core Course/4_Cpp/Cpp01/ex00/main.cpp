#include "Zombie.hpp"


int main()
{
    Zombie* heapZombie;

    heapZombie = newZombie("heapZombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("stackZombie");
}