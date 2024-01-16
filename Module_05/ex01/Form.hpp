#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		~Form();
		Form(const Form &other);
		Form	&operator=(const Form &other);

		void beSigned(Bureaucrat &bureau);

		const int	&getGradeSign() const;
		const int	&getGradeExec() const;
		const std::string	&getName() const;
		const bool &getIsSigned() const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &oStream, Form &form);

#endif