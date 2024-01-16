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

int main() {

	Bureaucrat example_01("Tiago", 2);

	try {
		Form f1("42_school", 42, 42);
		Form f2("Mister nr 1", 1, 1);
		std::cout << example_01 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		example_01.signForm(f1);
		std::cout << f1 << std::endl;
		example_01.signForm(f2);
		std::cout << f2 << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	return (0);
}
