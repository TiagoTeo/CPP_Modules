/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:08:40 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/09 17:14:17 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int	main() {
	std::string s = "HI THIS IS BRAIN";
	std::string *ptr = &s;
	std::string &ref = s;
	
	std::cout << "[" << &s << "] adress of string" << std::endl;
	std::cout << "[" << ptr << "] adress held by ptr" << std::endl;
	std::cout << "[" << &ref << "] adress held by ref" << std::endl;
	std::cout << "[" << s << "] value of string" << std::endl;
	std::cout << "[" << *ptr << "] value held by ptr" << std::endl;
	std::cout << "[" << ref << "] value held by ref" << std::endl;
}