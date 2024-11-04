#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void	setName(std::string);
		void	announce(void) const;
};

Zombie *zombieHorde(int nb, std::string name);

#endif
