/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:08:18 by bkiskac           #+#    #+#             */
/*   Updated: 2025/04/26 16:37:07 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void PhoneBook::searchContact() const
{
}

bool PhoneBook::showContact(int index) const
{
	return false;
}
