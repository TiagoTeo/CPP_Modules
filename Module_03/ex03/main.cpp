/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 12:33:40 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {

	DiamondTrap x("DDDDDD");
	
	x.whoAmI();
	x.guardGate();
	x.highFivesGuys();
	x.attack("something");
	return 0;
}