/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:29:42 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/08 16:10:25 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Constructor called" << std::endl;
	std::cout << "Name: " << name <<std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "Attack Damage: " << attackDamage << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string target) {
	if(energyPoints && hitPoints)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target \
		<< ", causing " << attackDamage << " points of damage!" << std::endl;
		std::cout << name << " energy points: " << energyPoints << std::endl;
		return ;
	}
	std::cout << name << " can't attack!" << std::endl;
	std::cout << name << " energy points: " << energyPoints << std::endl;
	std::cout << name << " hit points: " << hitPoints << std::endl;
}

void	ClapTrap::takeDamege(unsigned int amount) {
	if (hitPoints)
	{
		if (amount > hitPoints)
			hitPoints = 0;
		else
			hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount \
		<< " damage to their hit points" << std::endl;
		std::cout << name << " hit points: " << hitPoints << std::endl;
		return ;
	}
	std::cout << name << " can't take anymore damage! Hit points: " << hitPoints << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if(energyPoints && hitPoints)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " gets repaired by " << amount \
		<< "!" << std::endl;
		std::cout << name << " energy points: " << energyPoints << std::endl;
		std::cout << name << " hit points: " << hitPoints << std::endl;
		return ;
	}
	std::cout << name << " can't be repaired!" << std::endl;
	std::cout << name << " energy points: " << energyPoints << std::endl;
	std::cout << name << " hit points: " << hitPoints << std::endl;

}

std::string	ClapTrap::getName() {
	return (this->name);
}

unsigned int	ClapTrap::getAttackDamage() {
	return (this->attackDamage);
}