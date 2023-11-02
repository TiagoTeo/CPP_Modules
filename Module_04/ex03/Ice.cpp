/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:19 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/30 12:55:12 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &other) {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice &Ice::operator=(const Ice &other) {
	if (this != &other)
		typeMateria = other.getType();
	return (*this);
}

Ice	*Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter &target){

        std::cout << "* shoots an ice bolt at " << target.getName() \
        << " *"<< std::endl;
}