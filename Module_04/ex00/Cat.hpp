#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : virtual public Animal {
	public:
		Cat();
		virtual	~Cat();
		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);

		void	makeSound() const;
};

#endif