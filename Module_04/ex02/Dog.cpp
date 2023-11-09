/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/09 19:15:26 by mtiago-s         ###   ########.fr       */
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
	brain = new Brain();
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other)
	{
		type = other.getType();
		*brain = *(other.brain);
	}
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "* Bark *" << std::endl;
}

void	Dog::setBrainIdea(std::string idea, int index) {
	brain->setIdea(idea, index);
}

void Dog::showBrainIdea(int index){
    brain->showIdea(index);
}