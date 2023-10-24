/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:38:02 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/24 13:12:11 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {	
}

Point::Point(const float x, const float y) : x(x), y(y) {	
}

Point::~Point() {	
}

Point::Point(const Point &other) {
	*this = other;
}

Point	&Point::operator=(const Point &other) {
	if (this != &other)
	{
		this->x = other.getX();
		this->y = other.getY();
	}
	return (*this);
}

bool Point::operator==(Point const &other) const {
	return (x == other.x && y == other.y);
}


const Fixed	&Point::getX() const{
	return (x);
}

const Fixed	&Point::getY() const{
	return (y);
}
