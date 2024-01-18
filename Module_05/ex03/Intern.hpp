#ifndef INTERN_HPP
#define INTERN_HPP

#include <map>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;
class Bureaucrat;

class	Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);

        AForm *makeForm(std::string name, std::string target);

		class FormNameDoesntExist : public std::exception {
			private:
				virtual const char *what() const throw();
		};
};

#endif