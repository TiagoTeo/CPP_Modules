/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 15:47:01 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("NULL") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other)
		type = other.getType();
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "* Ordinary animal sound *" << std::endl;
}

void	Animal::setType(std::string newType) {
	this->type = newType;
}

std::string	Animal::getType() const {
	return (this->type);
}