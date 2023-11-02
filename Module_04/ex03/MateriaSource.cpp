/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:38:40 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/30 12:45:58 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++){
        inventory[i] = 0;
    }
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++){
        delete inventory[i];
    }
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other)
	{
		for (int i = 0; i < 4; i++){
       		delete inventory[i];
			inventory[i] = other.inventory[i]->clone();
    	}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *newMateria) {
	for (int i = 0; i < 4; i++){
		if (!inventory[i])
		{
			inventory[i] = newMateria;
			break ;
		}
    }
}
AMateria	*MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++){
		if (inventory[i] && inventory[i]->getType() == type) 
			return (inventory[i]->clone());
    }
	return (0);
}