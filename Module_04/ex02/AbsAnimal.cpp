/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbsAnimal.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 16:58:05 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbsAnimal.hpp"

AbsAnimal::AbsAnimal() : type("NULL") {
	std::cout << "AbsAnimal default constructor called" << std::endl;
}

AbsAnimal::~AbsAnimal() {
	std::cout << "AbsAnimal destructor called" << std::endl;
}

AbsAnimal::AbsAnimal(const AbsAnimal &other) {
	std::cout << "AbsAnimal copy constructor called" << std::endl;
	*this = other;
}

AbsAnimal &AbsAnimal::operator=(const AbsAnimal &other) {
	if (this != &other)
		type = other.getType();
	return (*this);
}

void	AbsAnimal::makeSound() const {
	std::cout << "* Ordinary Absanimal sound *" << std::endl;
}

void	AbsAnimal::setType(std::string newType) {
	this->type = newType;
}

std::string	AbsAnimal::getType() const {
	return (this->type);
}