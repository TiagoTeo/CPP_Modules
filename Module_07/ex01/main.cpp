#include "Iter.hpp"

void	increment(int &nb) {
	nb++;
}

void	decrement(int &nb) {
	nb--;
}

void	capitalize(std::string &str) {
	for (std::size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int main( void ) {
	int a[5] = {1, 2, 3, 4, 5};
	int len = 5;

	std::string str[5] = {"Hello", "World", "I", "am", "Teo"};
    ::iter<std::string>(str, len, ::printElememts);
	std::cout << std::endl;
	
	::iter<std::string>(str, len, capitalize);
    ::iter<std::string>(str, len, ::printElememts);
	std::cout << std::endl;

    ::iter(a, len, increment);
    ::iter(a, len, increment);
 	::iter(a, len, ::printElememts);
    std::cout << std::endl;

    ::iter(a, len, decrement);
    ::iter(a, len, decrement);
    ::iter(a, len, decrement);
 	::iter(a, len, ::printElememts);
    std::cout << std::endl;
	return 0;
}