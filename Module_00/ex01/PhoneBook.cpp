/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiago-s <mtiago-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:22:12 by mtiago-s          #+#    #+#             */
/*   Updated: 2023/10/03 16:09:13 by mtiago-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::shiftDown(){
	for (int i = 7; i > 0; i--) {
		this->ContactList[i] = this->ContactList[i - 1];
		this->ContactList[i].setIndex(i + 1);
	}
}

void	PhoneBook::AddContact(){
	std::string first = readPrompt("Enter first name: ");
	std::string last = readPrompt("Enter last name: ");
	std::string nick = readPrompt("Enter nickname: ");
	std::string number = readPrompt("Enter phone number: ");
	std::string secret = readPrompt("Enter darkest secret: ");
	this->shiftDown();
	this->ContactList[0].CreateContact(1, first, last, nick, number, secret);
}

void	PhoneBook::showSecret(){
	std::string	line;
	int			i;
	
	while (1)
	{
		line = readPrompt("Enter a index to see all details or press 'Q' to leave: ");
		if (line[0] == 'Q' && line.size() == 1)
			return ;
		else if (line.size() == 1 && line[0] >= '1' && line[0] <= '8')
		{
			i = line[0] - 49;
			if (!this->ContactList[i].getFirstName().empty())
				this->ContactList[i].DisplayContact();
			else
				std::cout << "Contact empty!" << std::endl;
		}
		else
			std::cout << "Not a valid index!" << std::endl;
	}	
}

void	PhoneBook::SearchContacts(){
	for (int i = 0; i < 8; i++){
		std::cout << std::setw(10) << this->ContactList[i].getIndex() << "|";
		if (this->ContactList[i].getFirstName().size() > 9)
	        std::cout << this->ContactList[i].getFirstName().substr(0,9) << "."<< "|";
	    else
	        std::cout << std::setw(10) << this->ContactList[i].getFirstName() << "|";
	    if (this->ContactList[i].getLastName().size() > 9)
	        std::cout << this->ContactList[i].getLastName().substr(0,9) << "."<< "|";
	    else
	        std::cout << std::setw(10) << this->ContactList[i].getLastName() << "|";
	    if (this->ContactList[i].getNickname().size() > 9)
	        std::cout << this->ContactList[i].getNickname().substr(0,9) << "."<< std::endl;
	    else
	        std::cout << std::setw(10) << this->ContactList[i].getNickname() << std::endl;
	}
	this->showSecret();
}