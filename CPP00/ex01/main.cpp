#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "ADD")
		{
			Contact c;
			std::string input;

			std::cout << "First Name: ";
			while (std::getline(std::cin, input) && input.empty())
				std::cout << "First Name cannot be empty. Try again: ";
			c.setFirstName(input);

			std::cout << "Last Name: ";
			while (std::getline(std::cin, input) && input.empty())
				std::cout << "Last Name cannot be empty. Try again: ";
			c.setLastName(input);

			std::cout << "Nickname: ";
			while (std::getline(std::cin, input) && input.empty())
				std::cout << "Nickname cannot be empty. Try again: ";
			c.setNickname(input);

			std::cout << "Phone Number: ";
			while (std::getline(std::cin, input) && input.empty())
				std::cout << "Phone Number cannot be empty. Try again: ";
			c.setPhoneNumber(input);

			std::cout << "Darkest Secret: ";
			while (std::getline(std::cin, input) && input.empty())
				std::cout << "Darkest Secret cannot be empty. Try again: ";
			c.setDarkestSecret(input);

			phoneBook.addContact(c);
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.listContacts();

			std::cout << "Index: ";
			if (!std::getline(std::cin, cmd))
				break;

			std::istringstream iss(cmd);
			int index;
			if (!(iss >> index))
			{
				std::cout << "Invalid index format." << std::endl;
				continue;
			}
			phoneBook.showContact(index);
		}
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}
