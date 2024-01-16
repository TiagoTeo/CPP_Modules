#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class	Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat	&operator=(const Bureaucrat &other);

		const int	&getGrade() const;
		const std::string	&getName() const;

		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form &form);

		class GradeTooHighException : public std::exception {
			private:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			private:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &oStream, Bureaucrat &burcrat);

#endif