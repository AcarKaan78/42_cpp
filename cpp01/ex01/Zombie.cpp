#include "Zombie.hpp"

Zombie::Zombie() : _name("Zombie")
{
	return ;
}

Zombie::Zombie(std::string name) : _name(name)
{
	return ;
}

Zombie::~Zombie()
{
	std::cout << _name << " is dead (for good this time)" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}
