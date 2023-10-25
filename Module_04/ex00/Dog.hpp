#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog : virtual public Animal {
	public:
		Dog();
		virtual	~Dog();
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);

		void	makeSound() const;
};

#endif