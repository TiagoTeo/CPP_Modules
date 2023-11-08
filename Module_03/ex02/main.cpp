/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/08 16:18:40 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {

	ClapTrap x("CLAP");
	FragTrap y("FRAG");

	y.highFivesGuys();
	
	y.attack(x.getName());
	x.takeDamege(y.getAttackDamage());

	x.attack(y.getName());
	if (x.getEnergyPoints() && x.getHitPoints())
		y.takeDamege(x.getAttackDamage());
	return 0;
}