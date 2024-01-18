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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("NoTarget") {
	std::cout << "Robotomy Request Form with no target default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target) {
	std::cout << "Robotomy Request Form constructor called with target: " << _target <<  std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Request Form's: " << _target << " destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {
	std::cout << "Robotomy Request Form copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	this->setIsSigned(other.getIsSigned());
	return (*this);
}

const std::string &RobotomyRequestForm::getTarget() const {
	return (_target);
}

const char *RobotomyRequestForm::NotSigned::what() const throw() {
	return ("Form is not signed, can't execute");
}

void RobotomyRequestForm::execute(Bureaucrat const &executer) const {
	std::cout << "Drrrrrrrrrr *drilling noises* drrrrrrrrr" << std::endl;
	if (!this->getIsSigned())
		throw RobotomyRequestForm::NotSigned();
	else if (executer.getGrade() > this->getGradeExec())
		throw RobotomyRequestForm::GradeTooLowException();
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int randomNumber = rand() % 2;
	if (!randomNumber)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomy has failed" << std::endl;
}

