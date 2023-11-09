/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:33:31 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/09 18:16:31 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <cstring>

Character::Character() : name("NULL"), floor(NULL) {
	for (int i = 0; i < 4; i++){
        materias[i] = 0;
    }
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string nameCharacter) : name(nameCharacter), floor(NULL) {
	for (int i = 0; i < 4; i++){
        materias[i] = 0;
    }
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++){
        delete materias[i];
    }
	if (floor) {
		for (int i = 0; floor[i]; i++) {
			delete floor[i];
		}
		delete[] floor;
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
	// std::cout << "Arsenal:" << std::endl;
	// for (int i = 0; i < 4; i++) {
	// 	if (materias[i])
	// 		std::cout << "[" << i << "] = " << materias[i]->getType() << std::endl;
	// 	else
	// 		std::cout << "[" << i << "] = 0" << std::endl;
	// }
}
void Character::unequip(int idx) {
	// for (int i = 0; i < 4; i++) {
	// 	if (materias[i])
	// 		std::cout << "[" << i << "] = " << materias[i]->getType() << std::endl;
	// 	else
	// 		std::cout << "[" << i << "] = 0" << std::endl;
	// }
	if (materias[idx])
		addFloor(materias[idx]);
	else
		std::cout << "Nothing to drop on the floor!" << std::endl;
	materias[idx] = 0;
}
void Character::use(int idx, ICharacter &target) {
	if (materias[idx])
		materias[idx]->use(target);
}

void Character::addFloor(AMateria *mat) {
	static int idx;
	AMateria	**temp;
	idx++;
	temp = new AMateria*[idx + 1];
	std::memset(temp, 0, (idx + 1) * sizeof(AMateria*));
	std::cout << mat->getType() << " has been dropped on the floor!" \
	<< std::endl;
	if (floor)
		std::memmove(temp, floor, (idx - 1) * sizeof(AMateria*));
	temp[idx - 1] = mat;
	delete[] floor;
	floor = temp;
}
