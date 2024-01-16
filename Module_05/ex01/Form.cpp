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

#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(75), _execGrade(75) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form constructor called with name: " << _name << ", sing grade: " << signGrade << ", exec grade: " << execGrade << std::endl;
}

Form::~Form() {
	std::cout << "Form's: " << _name << " destructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other.getName()), _isSigned(false), _signGrade(other.getGradeSign()), _execGrade(other.getGradeExec()) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
	if (this->_signGrade <= other.getGradeSign())
		this->_isSigned = other.getIsSigned();
	else
		throw Form::GradeTooLowException();
	return (*this);
}

const std::string &Form::getName() const {
	return (_name);
}

const int	&Form::getGradeSign() const {
	return (_signGrade);
}

const int	&Form::getGradeExec() const {
	return (_execGrade);
}

const bool &Form::getIsSigned() const {
	return (_isSigned);
}

void Form::beSigned(Bureaucrat &bureau) {
	if (bureau.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	else
		this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Form's can't get sign, grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form's can't get sign, grade too low");
}

std::ostream &operator<<(std::ostream &oStream, Form &form) {
	oStream << "Form's name: " << form.getName() << std::endl;
	oStream << "Form's signing grade: " << form.getGradeSign() << std::endl;
	oStream << "Form's execution grade: " << form.getGradeExec() << std::endl;
	oStream << "Is this form signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;
	return (oStream);
}