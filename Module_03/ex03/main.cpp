/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/08 16:27:13 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {

	DiamondTrap d("DIAMD");
	ClapTrap c("CLAP");
	// FragTrap f("FRAG");
	// ScavTrap s("SCAV");
	
	d.whoAmI();
	d.guardGate();
	d.highFivesGuys();
	d.attack("something");
	// d.attack(c.getName());
	// c.takeDamege(d.getAttackDamage());
	// c.beRepaired(5);
	return 0;
}