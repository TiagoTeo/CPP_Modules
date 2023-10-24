#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class	ClapTrap {
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap 		&operator=(const ClapTrap &other);
		void			attack(const std::string target);
		void			takeDamege(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName();
		unsigned int	getAttackDamage();
};

#endif