/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:05:42 by iskaraag          #+#    #+#             */
/*   Updated: 2025/05/26 18:19:40 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook pb;
	std::string command;

	std::cout << "\e[42mMY AWESOME PHONEBOOK\033[0m" << std::endl;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (std::getline(std::cin, command))
		{
			if (command == "ADD")
				pb.addContact();
			else if (command == "SEARCH")
				pb.searchContacts();
			else if (command == "EXIT")
				return 1;
			else if (command.empty())
				std::cout << "\033[1;33mNo command entered. Please type something.\033[0m" << std::endl;
			else
				std::cout << "\033[1;31mUnknown command.\033[0m" << std::endl;
		}
		else
			break;
	}
	return 0;
}
