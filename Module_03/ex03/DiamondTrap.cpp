/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:14:56 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 12:38:22 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
	this->name = "default";
	std::cout << "Diamond default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string nameDiamond) : ClapTrap(nameDiamond + "_clap_name"),
FragTrap(), ScavTrap(), name(nameDiamond) {
	std::cout << "DiamondTrap Constructor called" << std::endl;
	std::cout << "Name: " << name <<std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "Attack Damage: " << attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl; 
}