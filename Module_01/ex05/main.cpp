/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:31:22 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/10 16:54:48 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
	Harl a;
	std::string messages[7];
	messages[0] = "DEBUG";
	messages[1] = "OLA";
	messages[2] = "INFO";
	messages[3] = "WARNING";
	messages[4] = "ERROR";
	messages[5] = "OI";
	messages[6] = "";

	for (int i = 0; i < 7; i++)
	{
		std::cout << messages[i] << std::endl;
		a.complain(messages[i]);
		std::cout << std::endl;
	}
}