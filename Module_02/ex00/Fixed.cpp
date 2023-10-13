/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:53:11 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/13 17:27:53 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(Fixed const &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}