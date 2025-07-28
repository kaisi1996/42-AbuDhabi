#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
		  return (NULL);

    Zombie* hordeZombies = new Zombie[N];

    for (int i = 0; i < N ; i++)
    {
      hordeZombies[i].setName(name);
    }
    return (hordeZombies);
}
