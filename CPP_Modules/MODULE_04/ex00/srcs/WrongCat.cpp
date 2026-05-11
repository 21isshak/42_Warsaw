/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:08:09 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:39:08 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "WrongCat is constructed" << std::endl;
}

WrongCat::WrongCat(WrongCat const& copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
}

WrongCat&	WrongCat::operator=(WrongCat const& copy)
{
	std::cout << "WrongCat assignment operator overload called" << std::endl;
	if (this != &copy)
		_type = copy._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << _type << " is destructed" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WRONG___MEOOOOOOOW!" << std::endl;
}