/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:50:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 17:10:53 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	// const Animal* f = new Dog();
	// const Animal* g = new Cat();
	// delete f;//should not create a leak
	// delete g;
	
	Dog* i = new Dog();
	i->setBrainIdea("um", 1);
	i->setBrainIdea("dois", 2);
	i->setBrainIdea("tres", 3);
	
	Dog* j = i;
	delete i;
	
	std::cout << "1 = " << j->getBrainIdea(1) << \
	", 2 = " << j->getBrainIdea(2) << \
	", 3 = " << j->getBrainIdea(3) << std::endl;
	
	return (0);
}
