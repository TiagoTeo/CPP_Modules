#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : virtual public Animal {
	private:
		Brain* brain;
	public:
		Cat();
		virtual	~Cat();
		Cat(const Cat &other);
		Cat	&operator=(const Cat &other);

		void		makeSound() const;
		void		setBrainIdea(std::string idea, int index);
		std::string getBrainIdea(int index) const;
};

#endif