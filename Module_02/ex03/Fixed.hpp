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
		//OCF
		Fixed();
		~Fixed();
		Fixed(Fixed const &other);
		Fixed &operator=(Fixed const &other);

		//Aditional Constructors
		Fixed(const int n);
		Fixed(const float n);

		//Operator overloads
		//Arithmetic
		Fixed operator+(Fixed const &other) const;
		Fixed operator-(Fixed const &other) const;
		Fixed operator*(Fixed const &other) const;
		Fixed operator/(Fixed const &other) const;
		//Comparasion
		bool operator>(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
		bool operator>=(Fixed const &other) const;
		bool operator<=(Fixed const &other) const;
		bool operator==(Fixed const &other) const;
		bool operator!=(Fixed const &other) const;
		//Increment/Decrement
		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int n);
		Fixed operator--(int n);

		static Fixed&	min(Fixed &a, Fixed &b);
		static const Fixed&	min(Fixed const &a, Fixed const &b);
		static Fixed&	max(Fixed &a, Fixed &b);
		static const Fixed&	max(Fixed const &a, Fixed const &b);


		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void)	const;

		Fixed	abs() const;

};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif