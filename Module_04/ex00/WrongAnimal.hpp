#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
#include <iostream>

class	WrongAnimal {
	protected:
		std::string		type;
	public:
		WrongAnimal();
		virtual	~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal	&operator=(const WrongAnimal &other);

		virtual void	makeSound() const;
		void			setType(std::string newType);
		std::string		getType() const;
};

#endif