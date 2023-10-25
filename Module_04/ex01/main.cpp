/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:50:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 16:45:03 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {

	const Animal* f = new Dog();
	const Animal* g = new Cat();
	delete f;//should not create a leak
	delete g;

	std::cout << "---<|>---" << std::endl;

	Dog* i = new Dog();
	i->setBrainIdea("um", 1);
	i->setBrainIdea("dois", 2);
	i->setBrainIdea("tres", 3);
	
	Dog* j = i;
	delete i;
	
	std::cout << "1 = " << j->getBrainIdea(1) << \
	", 2 = " << j->getBrainIdea(2) << \
	", 3 = " << j->getBrainIdea(3) << std::endl;

	std::cout << "---<|>---" << std::endl;

	Dog* a = new Dog();
	a->setBrainIdea("um", 1);
	a->setBrainIdea("dois", 2);
	a->setBrainIdea("tres", 3);
	
	Dog* b = new Dog(*a);
	delete a;
	
	std::cout << "1 = " << b->getBrainIdea(1) << \
	", 2 = " << b->getBrainIdea(2) << \
	", 3 = " << b->getBrainIdea(3) << std::endl;

	//delete b; porque e que isto da merda

	std::cout << "---<|>---" << std::endl;

	Animal* arrayAnimals[10];

    for (int i = 0; i < 5; i++){
        arrayAnimals[i] = new Dog();
        std::cout << "-" << std::endl;

    }
    for (int i = 5; i < 10; i++){
        arrayAnimals[i] = new Cat();
        std::cout << "-" << std::endl;
    }

    for (int i = 9; i >= 0; i--){
        arrayAnimals[i]->makeSound();
        delete arrayAnimals[i];
    }
	
	return (0);
}
