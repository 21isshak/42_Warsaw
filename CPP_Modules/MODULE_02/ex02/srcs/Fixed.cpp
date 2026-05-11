/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:51:48 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/11 20:22:41 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

/**********************************************************/
/****CONSTRUCTORS&DECONSTRUCTOR****************************/
/**********************************************************/

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const int val)
{
	//std::cout << "Int constructor called" << std::endl;
	_value = val << _fractional_bits;
	return;
}

Fixed::Fixed(const float val)
{
	//std::cout << "Float constructor called" << std::endl;
	_value = roundf(val * (1 << _fractional_bits));
	return;
}

Fixed::Fixed(Fixed const& copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->_value = copy._value;
	return;
}

Fixed::~Fixed()
{
	//std::cout << "Deconstructor called" << std::endl;
	return;
}

/**********************************************************/
/*********OPERATOR_OVERLOADS*******************************/
/**********************************************************/

//operation overload
Fixed& Fixed::operator=(Fixed const& cpy)
{
	//std::cout << "Copy assigment operator called" << std::endl;
	if (this != &cpy)
	{
		this->_value = cpy.getRawBits();
	}
	return(*this);
}

//comparison operators
bool Fixed::operator>(Fixed var) const
{
	return (this->toFloat() > var.toFloat());
}

bool Fixed::operator<(Fixed var) const
{
	return (this->toFloat() < var.toFloat());
}

bool Fixed::operator>=(Fixed var) const
{
	return (this->toFloat() >= var.toFloat());
}

bool Fixed::operator<=(Fixed var) const
{
	return (this->toFloat() <= var.toFloat());
}

bool Fixed::operator==(Fixed var) const
{
	return (this->toFloat() == var.toFloat());
}

bool Fixed::operator!=(Fixed var) const
{
	return (this->toFloat() != var.toFloat());
}

//arithmetic operators
float  Fixed::operator+(Fixed var) const
{
	return (this->toFloat() + var.toFloat());
}

float Fixed::operator-(Fixed var) const
{
	return (this->toFloat() - var.toFloat());
}

float Fixed::operator*(Fixed var) const
{
	return (this->toFloat() * var.toFloat());
}

float Fixed::operator/(Fixed var) const
{
	return (this->toFloat() / var.toFloat());
}

//ostream overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num)
{
    os << fixed_num.toFloat();
    return os;
}

/**********************************************************/
/*********GETTER&SETTER************************************/
/**********************************************************/

int	Fixed::getRawBits(void) const
{
	//std::cout << "Member function getter called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int val)
{
	//std::cout << "Member function setter called" << std::endl;
	_value = val;
}

/**********************************************************/
/************CONVERTION_FUCNTIONS**************************/
/**********************************************************/

float	Fixed::toFloat(void) const
{
	return (float(_value) / (1 << _fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractional_bits);
}

/**********************************************************/
/*********INCREMENTIONS************************************/
/**********************************************************/

//post increment operators
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value--;
	return temp;
}

//pre increment operators
Fixed Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed Fixed::operator--(void)
{
	_value--;
	return *this;
}

/**********************************************************/
/********************MAX_MIN*******************************/
/**********************************************************/

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}