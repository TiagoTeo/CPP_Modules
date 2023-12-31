/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:29:33 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/09 18:15:59 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
	me->use(0, *bob);
    me->use(1, *bob);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	
	
	//me->use(3, *bob);
	me->use(0, *bob);
    me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
return 0;
}