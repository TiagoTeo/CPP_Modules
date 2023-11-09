#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character : public ICharacter {
	private:
		std::string		name;
		AMateria		*materias[4];
		AMateria		**floor;
	public:
		Character();
		Character(std::string nameCharacter);
		~Character();
		Character(const Character &other);
		Character	&operator=(const Character &other);

		const std::string	&getName() const;
		void equip(AMateria *mat);
        void unequip(int idx);
		void use(int idx, ICharacter &target);
		void addFloor(AMateria *mat);
};

#endif