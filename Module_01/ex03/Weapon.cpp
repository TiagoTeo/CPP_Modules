/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:22:33 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/09 18:03:14 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
	std::cout << "Weapon created!" << std::endl;
}

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {
	std::cout << this->type << " weapon has been destroyed" << std::endl;
}

const std::string	&Weapon::getType(void) {
	std::string &ref = this->type;
	return (ref);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}