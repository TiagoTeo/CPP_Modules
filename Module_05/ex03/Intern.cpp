/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:36:52 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 15:46:46 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern's: destructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
}

const char *Intern::FormNameDoesntExist::what() const throw() {
	return ("Form's name doesn't exist\nPossible names:\nShrubbery Creation\nRobotomy Request\nPresidential Pardon\n");
}

AForm *Intern::makeForm(std::string name, std::string target) {
    AForm *result = NULL;
    int i = 0;
    std::string formsNames[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
    while (i < 3 && formsNames[i].compare(name)) {
        i++;
    }
    switch (i + 1) {
        case 1:
            std::cout << "Intern creats Shrubbery Creation Form" << std::endl;
            result = new ShrubberyCreationForm(target);
            break;
        case 2:
            std::cout << "Intern creats Robotomy Request Form" << std::endl;
            result = new RobotomyRequestForm(target);
            break;
        case 3:
            std::cout << "Intern creats Presidential Pardon Form" << std::endl;
            result = new PresidentialPardonForm(target);
            break;
        default:
            throw FormNameDoesntExist();
    }
    return (result);
}