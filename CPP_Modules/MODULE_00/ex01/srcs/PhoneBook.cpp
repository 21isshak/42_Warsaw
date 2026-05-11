/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:05:47 by iskaraag          #+#    #+#             */
/*   Updated: 2025/05/26 18:19:24 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}

void PhoneBook::addContact()
{
	Contact newContact;
	newContact.setInfo();
	if (newContact.isValid())
	{
		contacts[currentIndex] = newContact;
		currentIndex = (currentIndex + 1) % 8;
		if (totalContacts < 8)
			totalContacts++;
		std::cout << "\e[4;37mContact added!\033[0m\n";
	}
	else
		std::cout << "All fields must be filled." << std::endl;
}

void PhoneBook::searchContacts() const
{
	if (totalContacts == 0)
	{
		std::cout << "No contacts to display." << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < totalContacts; i++)
		contacts[i].displayShort(i + 1);

	std::cout << "Enter index: ";
	std::string input;
	std::getline(std::cin, input); // we need to handle it as a string so we can handle "Enter" key and exec.

	if (input.empty())
	{
		std::cout << "\033[1;33mNo index entered.\nTry 'SEARCH' again with an index.\033[0m" << std::endl;
		return;
	}

	std::istringstream iss(input); // parsing string into an int

	int index;

	if (!(iss >> index) || index < 1 || index > totalContacts)
	{
		std::cout << "\033[1;31mInvalid index.\033[0m" << std::endl;
		return;
	}
	contacts[index - 1].displayFull();
}
