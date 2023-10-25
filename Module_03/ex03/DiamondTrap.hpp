#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string	name;
		using FragTrap::hitPoints;
		using FragTrap::attackDamage;
		using ScavTrap::energyPoints;
	public:
		DiamondTrap();
		DiamondTrap(std::string nameDiamond);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap	&operator=(const DiamondTrap &other);

		void	whoAmI();
};

#endif