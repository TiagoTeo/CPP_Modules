#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class	Fixed {
	private:
		int			rawBits;
		static int	fBits;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed &operator=(Fixed const &other);
		Fixed(const int n);
		Fixed(const float n);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	const;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif