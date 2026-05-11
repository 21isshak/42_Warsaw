/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:38 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 16:28:57 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "\x1B[33mDefault AAnimal is constructed\033[0m" << std::endl;
}

AAnimal::AAnimal(AAnimal const& copy)
{
	std::cout << "\x1B[33mAAnimal copy constructor called\033[0m" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(AAnimal const& copy)
{
	std::cout << "\x1B[33mAAnimal assigment operator called\033[0m" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return(*this);
}

AAnimal::~AAnimal()
{
	std::cout << "\x1B[33m" << _type << " type AAnimal is destructed\033[0m" << std::endl;
}

void	AAnimal::makeSound() const
{
	std::cout << "\x1B[33mANIMAL SOUND\033[0m" << std::endl;
}

std::string	AAnimal::getType() const
{
	return(_type);
}