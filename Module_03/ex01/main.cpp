/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/08 16:17:24 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {

	ClapTrap x("CLAP");
	ScavTrap y("SCAV");

	y.guardGate();
	
	y.attack(x.getName());
	x.takeDamege(y.getAttackDamage());

	x.attack(y.getName());
	return 0;
}