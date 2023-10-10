/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:31:22 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/10 17:22:49 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	Harl	h;
	
	if (ac != 2) {
		std::cerr << "Pleas enter one of the four levels {DEBUG; INFO; WARNING; ERROR}" << std::endl;
		return (1);
	}
	h.complain(av[1]);
}