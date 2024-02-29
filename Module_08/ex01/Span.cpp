#include "Span.hpp"

Span::Span(unsigned int N) : _max(N) {
	std::cout << "Span Constructor called" << std::endl;
}

Span::Span(const Span& copy) : _max(copy.getMax()) {
	std::cout << "Span Copy Constructor called" << std::endl;
	_arr.clear();
	for (unsigned int i = 0; i < copy._arr.size(); i++) {
		_arr.push_back(copy._arr[i]);
	}
}

Span& Span::operator=(const Span& assign) {
	std::cout << "Span Assignment Operator called" << std::endl;
	if (this != &assign)
	{
		this->_max = assign.getMax();
		_arr.clear();
		for (unsigned int i = 0; i < assign._arr.size(); i++)
		{
			_arr.push_back(assign._arr[i]);
		}
	}
    return *this;
}

Span::~Span() {
    std::cout << "Span Deconstructor called" << std::endl;
}

int	Span::getMax( void ) const {
	return this->_max;
}

std::vector<int> Span::getVector() const {
	return this->_arr;
}

void	Span::addNumber(int nb)
{
	if (_arr.size() + 1 > _max)
		throw FullArrayException();
	std::vector<int>::iterator it = _arr.begin();
	while (it != _arr.end() && nb >= *it)
		it++;
	_arr.insert(it, nb);
	
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (std::distance(start, end) > _max)
		throw std::exception();
	_arr.insert(_arr.end(), start, end);
}

void	Span::addListNumber(unsigned int amount)
{
	if (amount > this->_max)
		throw FullArrayException();
	srand(time(NULL));
	while (amount > 0)
	{
		int	randomValue = rand();
			addNumber(randomValue);
			amount--;
	}
}

int	Span::shortestSpan( void )
{
	int	shortest;
	std::vector<int> sorted = _arr;
	
	if ((int)_arr.size() < 2)
		throw EmptyArrayException();
	std::sort(sorted.begin(), sorted.end());
	shortest = _arr[1] - _arr[0];
	for (unsigned int i = 1; i < sorted.size(); i++)
		shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
	return shortest;
}

int	Span::longestSpan( void )
{
	std::vector<int> sorted = _arr;

	
	if ((int)_arr.size() < 2)
		throw EmptyArrayException();
	std::sort(sorted.begin(), sorted.end());
	return sorted.back() - sorted.front();
}

const char	*Span::FullArrayException::what() const throw () {
	return "This array has reached it's maximum capacity";
}

const char	*Span::EmptyArrayException::what() const throw () {
	return "Can't calculate span without at least 2 numbers";
}