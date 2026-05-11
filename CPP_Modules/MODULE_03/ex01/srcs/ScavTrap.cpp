/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:39:00 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/28 22:58:48 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " default constucter called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "ScavTrap " << _name << " is constucted" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& copy)
{
	std::cout << "ScavTrap " << "copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << _name << " was destructed" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& copy)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hit_points = copy._hit_points;
		_energy_points = copy._energy_points;
		_attack_damage = copy._attack_damage;
	}
	return (*this);
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
		std::cout << "ScavTrap " << _name << " is cannot attack" << target << std::endl;
	
		else if (_energy_points == 0)
		std::cout << "ScavTrap " << _name << " has no energy points to attack" << target << std::endl;
	
		else if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout << "ScavTrap " << _name << " attack " << target << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
}