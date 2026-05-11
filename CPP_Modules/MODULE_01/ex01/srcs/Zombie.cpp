/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:30:56 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 15:10:24 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name(""){}

Zombie::Zombie(std::string name): _name(name){}

Zombie::~Zombie(void)
{
	std::cout << _name << " is destructed" << std::endl;
}

void	Zombie::set_name(std::string name){this->_name = name;};

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

