#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class	AMateria {
	protected:
		std::string		typeMateria;
	public:
		AMateria();
		virtual	~AMateria();
		AMateria(const AMateria &other);
		AMateria	&operator=(const AMateria &other);
		AMateria(const std::string &type);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
		const std::string &getType() const;
};

#endif