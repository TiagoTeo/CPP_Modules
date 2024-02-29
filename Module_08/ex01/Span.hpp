#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>
# include <ctime>
# include <algorithm>


class	Span {
	private:
		std::vector<int> _arr;
		unsigned int _max;
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		std::vector<int>	getVector() const;
		int		getMax() const;
		void	addListNumber(unsigned int amount);
		void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();
		class FullArrayException : public std::exception {
			public:
				virtual const char* what() const throw ();
		};
		class EmptyArrayException : public std::exception {
			public:
				virtual const char* what() const throw ();
		};
};

#endif