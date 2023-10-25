/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 17:10:23 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	setType("Dog");
	brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called" << std::endl;
	brain = other.brain;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
	{
		type = other.getType();
		brain = other.brain;
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "* Bark *" << std::endl;
}

void	Dog::setBrainIdea(std::string idea, int index) {
	brain->setIdea(idea, index);
}

std::string	Dog::getBrainIdea(int index) const {
	return (brain->getIdea(index));
}