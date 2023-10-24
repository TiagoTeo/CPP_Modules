/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:31:48 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/24 16:47:55 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string scavName) {
	this->name = scavName;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
	std::cout << "Name: " << name <<std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "Attack Damage: " << attackDamage << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string target) {
	if(energyPoints && hitPoints)
	{
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target \
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
		std::cout << name << " energy points: " << energyPoints << std::endl;
		return ;
	}
	std::cout << "ScavTrap"  << name << " can't attack!" << std::endl;
	std::cout << name << " energy points: " << energyPoints << std::endl;
	std::cout << name << " hit points: " << hitPoints << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap"  << name << " is now on Gate keeper mode!" << std::endl;
}