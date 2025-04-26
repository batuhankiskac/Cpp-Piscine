#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class PhoneBook
{
	private:
		Contact contacts[8];
		int nextIndex;
		int totalContacts;
		static void printField(const std::string &s);
	public:
		PhoneBook();
		void addContact(const Contact &contact);
		void listContacts() const;
		bool showContact(int index) const;
};

#endif
