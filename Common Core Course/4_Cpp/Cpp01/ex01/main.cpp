#include "Zombie.hpp"

int main()
{
    Zombie* hordZombie;
    int n = 10;
    hordZombie = zombieHorde(n, "zombie");
    if (hordZombie == NULL)
		  return (1);
    for(int i = 0; i < n; i++)
      hordZombie[i].announce();
    delete[] (hordZombie);
}
