#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>


class	ElementNotFoundExeption : public std::exception {
	public:
		const char *what() const throw() {
			return "Element not found in container.";
		}
};
template <typename T> 
typename T::iterator easyfind(T &container, int element) {
	typename T::iterator it = std::find(container.begin(), container.end(), element);
		if (it == container.end())
			throw ElementNotFoundExeption();
		std::cout << "Element Found: ";
		return it;
}

#endif