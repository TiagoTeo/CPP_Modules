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

int main() {

	Bureaucrat tiago("Tiago", 137);
	Bureaucrat antonio("Antonio", 45);
	Bureaucrat vasco("Vasco", 5);


	AForm *f1 = new ShrubberyCreationForm("Teste_Tiago_1");
	AForm *f2 = new ShrubberyCreationForm("Teste_Antonio_1");
	AForm *f3 = new ShrubberyCreationForm("Teste_Vasco_1");

	AForm *f4 = new RobotomyRequestForm("Teste_Tiago_2");
	AForm *f5 = new RobotomyRequestForm("Teste_Antonio_2");
	AForm *f6 = new RobotomyRequestForm("Teste_Vasco_2");

	AForm *f7 = new PresidentialPardonForm("Teste_Tiago_3");
	AForm *f8 = new PresidentialPardonForm("Teste_Antonio_3");
	AForm *f9 = new PresidentialPardonForm("Teste_Vasco_3");


	try {
		std::cout << "--Tiago's tests--" << std::endl;
		std::cout << "--Variables--" << std::endl;
		std::cout << tiago;
		std::cout << *f1;
		std::cout << *f4;
		std::cout << *f7;
		std::cout << "--Trying to sign form's--" << std::endl;
		tiago.signForm(*f1);
		tiago.signForm(*f4);
		tiago.signForm(*f7);
		std::cout << *f1;
		std::cout << *f4;
		std::cout << *f7;
		std::cout << "--Trying to execute form's--" << std::endl;
		f1->execute(tiago);
		f4->execute(tiago);
		f7->execute(tiago);
		std::cout << "-------" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	try {
		std::cout << "--Antonio's tests--" << std::endl;
		std::cout << "--Variables--" << std::endl;
		std::cout << antonio;
		std::cout << *f2;
		std::cout << *f5;
		std::cout << *f8;
		std::cout << "--Trying to sign form's--" << std::endl;
		antonio.signForm(*f2);
		antonio.signForm(*f5);
		antonio.signForm(*f8);
		std::cout << *f2;
		std::cout << *f5;
		std::cout << *f8;
		std::cout << "--Trying to execute form's--" << std::endl;
		f2->execute(antonio);
		f5->execute(antonio);
		f8->execute(antonio);
		std::cout << "-------" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	try {
		std::cout << "--Vasco's tests--" << std::endl;
		std::cout << "--Variables--" << std::endl;
		std::cout << vasco;
		std::cout << *f3;
		std::cout << *f6;
		std::cout << *f9;
		std::cout << "--Trying to sign form's--" << std::endl;
		vasco.signForm(*f3);
		vasco.signForm(*f6);
		vasco.signForm(*f9);
		std::cout << *f3;
		std::cout << *f6;
		std::cout << *f9;
		std::cout << "--Trying to execute form's--" << std::endl;
		f3->execute(vasco);
		f6->execute(vasco);
		f9->execute(vasco);
		std::cout << "-------" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;
	delete f6;
	delete f7;
	delete f8;
	delete f9;

	return (0);
}
