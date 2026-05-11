/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:33:51 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 17:13:13 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL){}
HumanB::~HumanB(void){}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << _name << " doesn't have a wepon yet"<< std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
