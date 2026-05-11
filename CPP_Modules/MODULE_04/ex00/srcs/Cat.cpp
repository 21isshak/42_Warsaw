/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:43 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:34:37 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat is constructed" << std::endl;
}

Cat::Cat(Cat const& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat&	Cat::operator=(Cat const& copy)
{
	std::cout << "Cat assignment operator overload called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << _type << " is destructed" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MEOOOOOOOW!" << std::endl;
}