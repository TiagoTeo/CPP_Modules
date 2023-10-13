#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed {
	private:
		int					rawBits;
		static const int	fBits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed &operator=(Fixed const &other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif