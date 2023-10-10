/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:58 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/09 19:00:19 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie *zeds = zombieHorde(7, "Cracudo");
	for (int i = 0; i < 7; i++) {
		std::cout << "[" << i << "]";
		zeds[i].announce();
	}
	delete[] zeds;
}