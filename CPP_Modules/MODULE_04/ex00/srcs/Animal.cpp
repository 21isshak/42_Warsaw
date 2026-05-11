/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:38 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:36:56 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "\x1B[33mDefault Animal is constructed\033[0m" << std::endl;
}

Animal::Animal(Animal const& copy)
{
	std::cout << "\x1B[33mAnimal copy constructor called\033[0m" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(Animal const& copy)
{
	std::cout << "\x1B[33mAnimal assigment operator called\033[0m" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return(*this);
}

Animal::~Animal()
{
	std::cout << "\x1B[33m" << _type << " type Animal is destructed\033[0m" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "\x1B[33mANIMAL SOUND\033[0m" << std::endl;
}

std::string	Animal::getType() const
{
	return(_type);
}