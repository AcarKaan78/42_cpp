#include "Zombie.hpp"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	Zombie		*ZombieHorde;
	int			NbZombie;
	std::string	nm = "zombie";

	if (argc == 1 || atoi(argv[1]) <= 0)
		NbZombie = 10;
	else
		NbZombie = atoi(argv[1]);
	if (argc >= 3)
		nm = argv[2];
	
	ZombieHorde = zombieHorde(NbZombie, nm);

	for (int i = 0; i < NbZombie; i++)
		ZombieHorde[i].announce();
	
	delete [] ZombieHorde;
	std::cout << "The horde of " << NbZombie << " zombies has been eradicated." << std::endl;
	return (0);
}
