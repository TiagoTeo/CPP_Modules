/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:04:41 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/07 16:20:21 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	checks(const Point a, const Point b, const Point c, const Point point) {
	if (a == point || b == point || c == point)
		return (1);
	return (0);
}

Fixed	area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3) {
	return ((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)).abs() / Fixed(2.0f));
}

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	//checks if the point is a vertex
	if (checks(a, b, c, point))
		return (false);
	//calculates the area of the triangle
	Fixed A = area(a.getX(), a.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	//calculates every possible area with point and the vertexs
	Fixed B = area(point.getX(), point.getY(), b.getX(), b.getY(), c.getX(), c.getY());
	Fixed C = area(a.getX(), a.getY(), point.getX(), point.getY(), c.getX(), c.getY());
	Fixed D = area(a.getX(), a.getY(), b.getX(), b.getY(), point.getX(), point.getY());
	//checks if the point is in one of the lines of the triangle
	if (B == 0 || C == 0 || D == 0)
		return (false);
	//if all areas add up the area A will be the sums of the others. if not the point is outside the triangle
	return (A == (B + C + D));
}