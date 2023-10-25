/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 16:35:38 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	setType("Cat");
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
	std::cout << "Cat copy constructor called" << std::endl;
	brain = other.brain;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other)
	{
		type = other.getType();
		brain = other.brain;
	}
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "* Miau *" << std::endl;
}

void	Cat::setBrainIdea(std::string idea, int index) {
	brain->setIdea(idea, index);
}

std::string	Cat::getBrainIdea(int index) const {
	return (brain->getIdea(index));
}