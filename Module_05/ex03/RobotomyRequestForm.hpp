#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	private:
		const std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);

		const std::string	&getTarget() const;

		void execute(Bureaucrat const &executer) const;

		class NotSigned : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif