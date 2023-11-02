#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria {
	protected:
		std::string		typeMateria;
	public:
		Cure();
		~Cure();
		Cure(const Cure &other);
		Cure	&operator=(const Cure &other);

		Cure	*clone() const;
		void use(ICharacter &target);
};

#endif