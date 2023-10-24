/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/24 16:17:25 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {

	ClapTrap x = ClapTrap("Otario 1");
	ClapTrap y = ClapTrap("Otario 2");

	x.attack(y.getName());
	y.takeDamege(x.getAttackDamage());
	y.beRepaired(1);
	y.attack(x.getName());
	x.takeDamege(y.getAttackDamage());

	std::cout << std::endl << "loop para acabar com energypoints" << std::endl;
	for (int i = 0; i < 10; i++)
		x.beRepaired(1);

	std::cout << std::endl << "loop para acabar com hitpoints" << std::endl;
	for (int i = 0; i < 4; i++)
		y.takeDamege(5);

	return 0;
}