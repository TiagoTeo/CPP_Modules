#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact {
	private:
		int index;
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string	phoneNumber;
		std::string darkestSecret;
	public:
		Contact(void);
		~Contact(void);
		int	getIndex(void);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		void	setIndex(int i);
		void	CreateContact(int id, std::string first, std::string last, std::string nick, std::string number, std::string secret);
		void	DisplayContact(void);
};

#endif