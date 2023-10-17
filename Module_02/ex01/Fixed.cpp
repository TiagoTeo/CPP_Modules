/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:53:11 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/17 16:22:42 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::fBits = 8;

Fixed::Fixed() { //Default constructor
	rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() { //Destructor
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) { // Copy constructor
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(Fixed const &other) { //Copy assignment operator
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << fBits);
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	//std::cout << "F = " << n << std::endl << "1 << fBits = " << (1 << fBits) << std::endl << "n * (1 << fBits) = " << n * (1 << fBits) << std::endl << "roundf(n * (1 << fBits) = " << roundf(n * (1 << fBits)) << std::endl;
	this->setRawBits(roundf(n * (1 << fBits)));
}

int Fixed::getRawBits(void) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return (rawBits);
}

void	Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->getRawBits() / (1 << fBits));
}

int	Fixed::toInt(void) const {
	return (this->getRawBits() >> fBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}