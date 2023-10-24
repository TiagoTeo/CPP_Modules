/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/24 14:51:30 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point);

int main( void ) {
	Point a(1, 1);
	Point b(6, 1);
	Point c(3.5, 6);

	std::cout << "Triangle: " << std::endl \
	<< "A = (" << a.getX() << ", " << a.getY() << ")" << std::endl \
	<< "B = (" << b.getX() << ", " << b.getY() << ")" << std::endl \
	<< "C = (" << c.getX() << ", " << c.getY() << ")" << std::endl;

	Point point(3.5, 1); // edge
	std::cout << "X = (" << point.getX() << ", " << point.getY() << ")" << std::endl;
	std::cout << bsp(a, b, c, point) << std::endl;
	Point point1(1, 1); //vertex ==
	std::cout << "X = (" << point1.getX() << ", " << point1.getY() << ")" << std::endl;
	std::cout << bsp(a, b, c, point1) << std::endl;
	Point point2(5, 2); //inside
	std::cout << "X = (" << point2.getX() << ", " << point2.getY() << ")" << std::endl;
	std::cout << bsp(a, b, c, point2) << std::endl;
	Point point3(4, 6); //outside
	std::cout << "X = (" << point3.getX() << ", " << point3.getY() << ")" << std::endl;
	std::cout << bsp(a, b, c, point3) << std::endl;
	return 0;
}