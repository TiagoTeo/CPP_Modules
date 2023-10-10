/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:42:40 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/10 17:23:47 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	this->levels[0] = "DEBUG";
	this->levels[1] = "INFO";
	this->levels[2] = "WARNING";
	this->levels[3] = "ERROR";
}

Harl::~Harl() {
	// std::cout << "Harl has been destroyed." << std::endl;
}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl << " I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl << " I cannot believe adding extra bacon costs more money." << std::endl << "You didn’t put enough bacon in my burger!" << std::endl << " If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl << " I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl << " This is unacceptable!" << std::endl << "I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	int	n = -1;
	
	for (int i = 0; i < 4; i++) {
		if (this->levels[i] == level) {
			n = i;
			break ;
		}
			
	}
	switch(n) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default: 
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}