/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:58 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/09 16:48:38 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie zed("Tomas");

	Zombie *b = newZombie("Teo");
	randomChump("Vasco");
	b->announce();
	zed.announce();
	delete b;
}