/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:48 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:33:34 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "Dog is constructed" << std::endl;
}

Dog::Dog(Dog const& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog&	Dog::operator=(Dog const& copy)
{
	std::cout << "Dog assignment operator overload called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << _type << " is destructed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "WUFF! WUFF! WUFF!" << std::endl;
}