/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:08:04 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:37:38 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "\x1B[35mDefault WrongAnimal is constructed\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& copy)
{
	std::cout << "\x1B[35mWrongAnimal copy constructor called\033[0m" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& copy)
{
	std::cout << "\x1B[35mAnimal assigment operator called\033[0m" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\x1B[35m" << _type << " type WrongAnimal is destructed\033[0m" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "\x1B[35mWRONG ANIMAL SOUND\033[0m" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return(_type);
}