/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:03:23 by bkiskac           #+#    #+#             */
/*   Updated: 2025/04/26 16:09:34 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

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
		void searchContact() const;
		bool showContact(int index) const;
};

#endif
