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
		example_01.incrementGrade();
		std::cout << example_01;
		example_01.incrementGrade();
		std::cout << example_01;
		example_01.incrementGrade();
		std::cout << example_01;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	Bureaucrat example_02("Andre", 148);

	try {
		example_02.decrementGrade();
		std::cout << example_02;
		example_02.decrementGrade();
		std::cout << example_02;
		example_02.decrementGrade();
		std::cout << example_02;
	} catch (std::exception &e) {
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	return (0);
}
