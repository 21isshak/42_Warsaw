/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:39:00 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/29 18:25:07 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "\x1B[33mScavTrap " << _name << " default constucter called\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout << "\x1B[33mScavTrap " << _name << " is constucted\033[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& copy)
{
	std::cout << "\x1B[33mScavTrap " << "copy constructor called\033[0m" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\x1B[33mScavTrap: " << _name << " was destructed\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& copy)
{
	std::cout << "\x1B[33mAssignment operator called\033[0m" << std::endl;
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
	std::cout << "\x1B[33mScavTrap " << _name << " is now in Gate keeper mode\033[0m" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
		std::cout << "\033[3;100;31mScavTrap " << _name << " is cannot attack" << target << "\033[0m" << std::endl;
	
	else if (_energy_points == 0)
		std::cout << "\033[3;100;31mScavTrap " << _name << " has no energy points to attack" << target << "\033[0m" << std::endl;
	
	else if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout << "\033[3;100;31mScavTrap " << _name << " attack " << target << " causing " << _attack_damage << " damage\033[0m" << std::endl;
		_energy_points--;
	}
}