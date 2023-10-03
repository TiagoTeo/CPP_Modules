#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

std::string	readPrompt(std::string prompt);

class PhoneBook {
	private:
		Contact ContactList[8];
		void	shiftDown(void);
		void	showSecret(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	AddContact(void);
		void	SearchContacts(void);
};


#endif