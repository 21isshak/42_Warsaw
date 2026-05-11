/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:33:58 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 16:57:54 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type(""){}
Weapon::Weapon(std::string type) : _type(type){}
Weapon::~Weapon(void){}

void	Weapon::setType(std::string type)
{
	_type = type;
}

const std::string& Weapon::getType(void) const
{
	return (_type);
}
