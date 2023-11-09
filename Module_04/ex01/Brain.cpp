/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:10:41 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/11/09 19:02:24 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other)
	{
		for(int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}		
	}
	return (*this);
}

void	Brain::setIdea(std::string idea, int index) {
	this->ideas[index] = idea;
}

void	Brain::showIdea(int index){
    std::cout <<  ideas[index] << std::endl;
}