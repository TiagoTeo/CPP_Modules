#ifndef ABSANIMAL_HPP
#define ABSANIMAL_HPP
#include <string>
#include <iostream>

class	AbsAnimal {
	protected:
		std::string		type;
	public:
		AbsAnimal();
		virtual	~AbsAnimal();
		AbsAnimal(const AbsAnimal &other);
		AbsAnimal	&operator=(const AbsAnimal &other);

		virtual void	makeSound() const = 0;
		void			setType(std::string newType);
		std::string		getType() const;
};

#endif