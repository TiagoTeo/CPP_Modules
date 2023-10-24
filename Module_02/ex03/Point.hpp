#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point &other);
		Point	&operator=(const Point &other);
		bool operator==(Point const &other) const;
		const Fixed	&getX() const;
		const Fixed	&getY() const;
};

#endif
