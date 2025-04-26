#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0), totalContacts(0) {}

void PhoneBook::printField(const std::string &s)
{
	if (s.length() > 10)
		std::cout << s.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << s;
}

void PhoneBook::addContact(const Contact &contact)
{
	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
}

void PhoneBook::listContacts() const
{
	std::cout << std::setw(10) << "Index" << '|' \
			  << std::setw(10) << "First Name" << '|' \
			  << std::setw(10) << "Last Name" << '|' \
			  << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < totalContacts; i++)
	{
		std::cout << std::setw(10) << i << "|";
		printField(contacts[i].getFirstName());
		std::cout << "|";
		printField(contacts[i].getLastName());
		std::cout << "|";
		printField(contacts[i].getNickname());
		std::cout << std::endl;
	}
}

bool PhoneBook::showContact(int index) const
{
	if (index < 0 || index >= totalContacts)
	{
		std::cout << "Invalid Index." << std::endl;
		return (false);
	}
	contacts[index].printContact();
	return (true);
}
