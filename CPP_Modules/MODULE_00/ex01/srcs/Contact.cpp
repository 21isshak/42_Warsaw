/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:05:55 by iskaraag          #+#    #+#             */
/*   Updated: 2025/05/26 18:19:20 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string formatField(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void Contact::setInfo()
{
	std::cout << "Enter First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, darkestSecret);
}

bool Contact::isValid() const
{
	return (!firstName.empty() && !lastName.empty() && !nickname.empty() &&
			!phoneNumber.empty() && !darkestSecret.empty());
}

void Contact::displayShort(int index) const
{
	std::cout << std::setw(10) << index << "|"
			  << std::setw(10) << formatField(firstName) << "|"
			  << std::setw(10) << formatField(lastName) << "|"
			  << std::setw(10) << formatField(nickname) << std::endl;
}

void Contact::displayFull() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
