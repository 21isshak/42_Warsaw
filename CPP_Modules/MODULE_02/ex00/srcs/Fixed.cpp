/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:51:48 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/19 20:59:07 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = copy._value;
	return;
}

Fixed& Fixed::operator=(Fixed const& cpy)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &cpy)
	{
		this->_value = cpy.getRawBits();
	}
	return(*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "Member function getter called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int val)
{
	std::cout << "Member function setter called" << std::endl;
	_value = val;
}
