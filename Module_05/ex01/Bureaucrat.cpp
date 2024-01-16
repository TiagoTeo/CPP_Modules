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

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(NULL), _grade(0){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called with name: " << _name << " and grade:" << _grade << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat's: " << _name << " destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
}

const int &Bureaucrat::getGrade() const {
	return (this->_grade);
}

const std::string &Bureaucrat::getName() const {
	return (_name);
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
}
void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat's can't get any higher (it's at 1)");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat's can't get any lower (it's at 150)");
}

std::ostream &operator<<(std::ostream &oStream, Bureaucrat &burcrat) {
	return (oStream << burcrat.getName() << " bureaucrat's grade " << burcrat.getGrade() << std::endl);
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << "Bureaucrat " << _name << " signed " << form.getName() << " form!" << std::endl;
	}
	catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << _name << " couldn't sign " << form.getName() << " because his grade is to low" << std::endl;
	}
}