/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:33:31 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/07 16:52:31 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("NULL") {
	for (int i = 0; i < 4; i++){
        materias[i] = 0;
    }
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string nameCharacter) : name(nameCharacter) {
	for (int i = 0; i < 4; i++){
        materias[i] = 0;
    }
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++){
        delete materias[i];
    }
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character &other) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character &Character::operator=(const Character &other) {
	if (this != &other)
	{
		name = other.getName();
		for (int i = 0; i < 4; i++){
       		delete materias[i];
			materias[i] = other.materias[i]->clone();
    	}
	}
	return (*this);
}

const std::string	&Character::getName() const {
	return (this->name);
}

void Character::equip(AMateria *mat) {
	std::cout << mat->getType() << " has been equiped!" \
	<< std::endl;
	for(int i = 0; i < 4; i++){
        if (!materias[i]){
            materias[i] = mat;
            break;
        }
    }
}
void Character::unequip(int idx) {
	delete materias[idx];
	materias[idx] = 0;
}
void Character::use(int idx, ICharacter &target) {
	if (materias[idx])
		materias[idx]->use(target);
}