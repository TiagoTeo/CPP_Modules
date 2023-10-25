#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string fragName);
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);

		void	highFivesGuys();
};

#endif