#include "RPN.hpp"

int main (int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: invalid number of aguments" << std::endl;
		return (1);
	}
	RPN rpn(av[1]);
}