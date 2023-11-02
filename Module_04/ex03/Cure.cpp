/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:19 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/30 12:57:58 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &other) {
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other)
		typeMateria = other.getType();
	return (*this);
}

Cure	*Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter &target){

        std::cout << "* heals " << target.getName() \
        << "’s wounds *"<< std::endl;
}