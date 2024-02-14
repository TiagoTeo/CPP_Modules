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

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("NoTarget") {
	std::cout << "Presidential Pardon Form with no target default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target) {
	std::cout << "Presidential Pardon Form constructor called with target: " << _target <<  std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Pardon Form's: " << _target << " destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const {
	return (_target);
}

const char *PresidentialPardonForm::NotSigned::what() const throw() {
	return ("Form is not signed, can't execute");
}

void PresidentialPardonForm::execute(Bureaucrat const &executer) const {
	if (!this->getIsSigned())
		throw PresidentialPardonForm::NotSigned();
	else if (executer.getGrade() > this->getGradeExec())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << _target << " has been pardon by Zaphod Beeblebrox" << std::endl;
}

