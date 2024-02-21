#include "PmergeMe.hpp"

int main (int ac, char **av) {
	if (ac < 2) {
		std::cout << "Error: invalid number of aguments" << std::endl;
		return (1);
	}
	try { 
		PmergeMe PmergeMe(av + 1);
	} catch (PmergeMe::negativeNumber &e) {
		std::cerr << e.what() << std::endl;
	} catch (PmergeMe::notNumber &e) {
		std::cerr << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}