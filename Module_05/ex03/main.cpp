/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:50:23 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/25 16:06:39 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	Bureaucrat vasco("Vasco", 5);

	Intern n;

	try {
		std::cout << "--f1's tests--" << std::endl;
		std::cout << "--Variables--" << std::endl;
		AForm *f1 = n.makeForm("Shrubbery Creation", "Teste_Vasco_1");
		std::cout << vasco;
		std::cout << *f1;
		std::cout << "--Trying to sign form's--" << std::endl;
		vasco.signForm(*f1);
		std::cout << *f1;
		std::cout << "--Trying to execute form's--" << std::endl;
		f1->execute(vasco);
		delete f1;
		std::cout << "-------" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	try {
		std::cout << "--f2's tests--" << std::endl;
		std::cout << "--Variables--" << std::endl;
		AForm *f2 = n.makeForm("Robotomy Request", "Teste_Vasco_2");
		std::cout << vasco;
		std::cout << *f2;
		std::cout << "--Trying to sign form's--" << std::endl;
		vasco.signForm(*f2);
		std::cout << *f2;
		std::cout << "--Trying to execute form's--" << std::endl;
		f2->execute(vasco);
		delete f2;
		std::cout << "-------" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	try {
		std::cout << "--f3's tests--" << std::endl;
		std::cout << "--Variables--" << std::endl;
		AForm *f3 = n.makeForm("Presidential Pardon", "Teste_Vasco_3");
		std::cout << vasco;
		std::cout << *f3;
		std::cout << "--Trying to sign form's--" << std::endl;
		vasco.signForm(*f3);
		std::cout << *f3;
		std::cout << "--Trying to execute form's--" << std::endl;
		f3->execute(vasco);
		delete f3;
		std::cout << "-------" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	try {
		std::cout << "--f4's tests--" << std::endl;
		std::cout << "--Variables--" << std::endl;
		AForm *f4 = n.makeForm("Shation", "Teste_Vasco_4");
		std::cout << vasco;
		std::cout << *f4;
		std::cout << "--Trying to sign form's--" << std::endl;
		vasco.signForm(*f4);
		std::cout << *f4;
		std::cout << "--Trying to execute form's--" << std::endl;
		f4->execute(vasco);
		delete f4;
		std::cout << "-------" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}


	return (0);
}
