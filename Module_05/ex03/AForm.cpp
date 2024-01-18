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

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(75), _execGrade(75) {
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called with name: " << _name << ", sing grade: " << signGrade << ", exec grade: " << execGrade << std::endl;
}

AForm::~AForm() {
	std::cout << "Form's: " << _name << " destructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other.getName()), _isSigned(false), _signGrade(other.getGradeSign()), _execGrade(other.getGradeExec()) {
	std::cout << "Form copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other) {
	if (this->_signGrade <= other.getGradeSign())
		this->_isSigned = other.getIsSigned();
	else
		throw AForm::GradeTooLowException();
	return (*this);
}

const std::string &AForm::getName() const {
	return (_name);
}

const int	&AForm::getGradeSign() const {
	return (_signGrade);
}

const int	&AForm::getGradeExec() const {
	return (_execGrade);
}

const bool &AForm::getIsSigned() const {
	return (_isSigned);
}

void AForm::setIsSigned(bool sign) {
	_isSigned = sign;
}

void AForm::beSigned(Bureaucrat &bureau) {
	if (bureau.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	else
		this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Form's can't get sign, grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Form's can't get sign, grade too low");
}

const char *AForm::AFormNotSigned::what() const throw() {
	return ("This form is not signed!");
}

std::ostream &operator<<(std::ostream &oStream, AForm &AForm) {
	oStream << "Form's name: " << AForm.getName() << std::endl;
	oStream << "Form's signing grade: " << AForm.getGradeSign() << std::endl;
	oStream << "Form's execution grade: " << AForm.getGradeExec() << std::endl;
	oStream << "Is this Form signed: " << (AForm.getIsSigned() ? "yes" : "no") << std::endl;
	return (oStream);
}