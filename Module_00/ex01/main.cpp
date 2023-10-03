/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:24:09 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/03 15:33:46 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	only_space(std::string str)
{
	int size = str.size();
	for (int i = 0; i < size; i++) {
		if (!std::isspace(str[i]))
			return (0);
	}
	return (1);
}

std::string	readPrompt(std::string prompt)
{
	std::string	line;
	std::cout << prompt;
	std::getline(std::cin, line);
	while (line.empty() || only_space(line))
	{
		std::cout << "Can't be empty!" << std::endl;
		std::cout << prompt;
		std::getline(std::cin, line);
	}
	return (line);
}

int ft_strcmp(const std::string str1, const std::string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();
	int minLen = std::min(len1, len2);

	for (int i = 0; i < minLen; ++i) {
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	}
	if (len1 != len2)
		return (len1 - len2);
	return (0);
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (1)
	{
		command = readPrompt("Enter a command: ");
		if (!ft_strcmp(command, "ADD"))
			phonebook.AddContact();
		else if (!ft_strcmp(command, "SEARCH"))
			phonebook.SearchContacts();
		else if (!ft_strcmp(command, "EXIT"))
			break ;
		else
			std::cout << "command not found" << std::endl;
	}
}