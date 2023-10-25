#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : virtual public Animal {
	private:
		Brain* brain;
	public:
		Dog();
		virtual	~Dog();
		Dog(const Dog &other);
		Dog	&operator=(const Dog &other);

		void		makeSound() const;
		void		setBrainIdea(std::string idea, int index);
		std::string getBrainIdea(int index) const;
};

#endif