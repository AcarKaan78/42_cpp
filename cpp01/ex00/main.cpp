#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	std::cout << "stack Zombies are here" << std::endl;
	Zombie	zombie1("Zombie1");
	Zombie	zombie2("Zombie2");
	Zombie	zombie3;

	zombie1.announce();
	zombie2.announce();
	zombie3.announce();
	randomChump("randomChump");

	std::cout << std::endl;
	std::cout << "heap Zombies are here" << std::endl;
	Zombie	*HeapZ;

	HeapZ = newZombie("HeapZ");
	HeapZ->announce();
	delete(HeapZ);

	return (0);
}