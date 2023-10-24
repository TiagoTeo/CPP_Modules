/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:53:11 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/24 13:04:15 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	Fixed::fBits = 8;

//OCF
Fixed::Fixed() { //Default constructor
	rawBits = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() { //Destructor
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) { // Copy constructor
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(Fixed const &other) { //Copy assignment operator
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.getRawBits();
	return (*this);
}

//Overload constructor fts
Fixed::Fixed(const int n) {
	// std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n << fBits);
}

Fixed::Fixed(const float n) {
	// std::cout << "Float constructor called" << std::endl;
	//std::cout << "F = " << n << std::endl << "1 << fBits = " << (1 << fBits) << std::endl << "n * (1 << fBits) = " << n * (1 << fBits) << std::endl << "roundf(n * (1 << fBits) = " << roundf(n * (1 << fBits)) << std::endl;
	this->setRawBits(roundf(n * (1 << fBits)));
}

//Operator overloads
//Arithmetic
Fixed	Fixed::operator+(Fixed const &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(Fixed const &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(Fixed const &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(Fixed const &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

//Comparasion
bool	Fixed::operator>(Fixed const &other) const {
	return (rawBits > other.rawBits);
}

bool	Fixed::operator<(Fixed const &other) const {
	return (rawBits < other.rawBits);
}

bool	Fixed::operator>=(Fixed const &other) const {
	return (rawBits >= other.rawBits);
}

bool	Fixed::operator<=(Fixed const &other) const {
	return (rawBits <= other.rawBits);
}

bool	Fixed::operator==(Fixed const &other) const {
	return (rawBits == other.rawBits);
}

bool	Fixed::operator!=(Fixed const &other) const {
	return (rawBits != other.rawBits);
}

//Increment/Decrement
Fixed	&Fixed::operator++(void) {
	this->rawBits++;
	return (*this);
}

Fixed	&Fixed::operator--(void) {
	this->rawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int n) {
	(void)n;
	Fixed temp(this->toFloat());
	this->rawBits++;
	return (temp);
}

Fixed	Fixed::operator--(int n) {
	(void)n;
	Fixed temp(this->toFloat());
	this->rawBits--;
	return (temp);
}

//Insertion
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return (os);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b ? a : b);
}

//Member fts
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

Fixed	Fixed::abs() const {
	if (*this < 0)
		return (*this * -1);
	return (*this);
}