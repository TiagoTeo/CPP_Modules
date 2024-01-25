#include "ScalarConverter.hpp"

int	main (int ac, char **av)
{
	if (ac != 2)
		return 0;
	try {
		ScalarConverter::converter(av[1]);
	} catch (std::exception &e) {
		std::cout << e.what();
	}
	return 1;	
}