/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/24 17:03:28 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {

	ClapTrap x("CLAP");
	FragTrap y("SCAV");

	y.highFivesGuys();
	
	y.attack(x.getName());
	x.takeDamege(y.getAttackDamage());

	x.attack(y.getName());
	if (x.getEnergyPoints() && x.getHitPoints())
		y.takeDamege(x.getAttackDamage());
	return 0;
}