#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _execGrade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);

		void beSigned(Bureaucrat &bureau);
		virtual void execute(Bureaucrat const &executer) const = 0;

		const int	&getGradeSign() const;
		const int	&getGradeExec() const;
		const std::string	&getName() const;
		const bool &getIsSigned() const;

		void setIsSigned(bool sign);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class AFormNotSigned : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &oStream, AForm &form);

#endif