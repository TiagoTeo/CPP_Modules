#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

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

		int	&getGrade();
		const std::string	&getName() const;

		void		incrementGrade();
		void		decrementGrade();

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