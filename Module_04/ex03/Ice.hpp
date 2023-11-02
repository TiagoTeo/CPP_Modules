#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria {
	protected:
		std::string		typeMateria;
	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice	&operator=(const Ice &other);

		Ice	*clone() const;
		void use(ICharacter &target);
};

#endif