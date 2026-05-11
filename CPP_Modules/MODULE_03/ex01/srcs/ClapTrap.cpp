/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:04:34 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/28 22:39:03 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << _name << " default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string const& name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << _name << " is constructed." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& copy)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& copy)
{
	std::cout << "Copy assigment operator called." << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hit_points = copy._hit_points;
		_energy_points = copy._energy_points;
		_attack_damage = copy._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " destructed." << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
		std::cout << "ClapTrap " << _name << " is cannot attack" << target << std::endl;
	
		else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " has no energy points to attack" << target << std::endl;
	
		else if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout << "ClapTrap " << _name << " attack " << target << " causing " << _attack_damage << " damage" << std::endl;
		_energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
	
	else if (_hit_points < (int)amount)
	{
		_hit_points = 0;
		std::cout << "ClapTrap " << _name << " was attacked and died" << std::endl;
	}
	
	else
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " was attacked. Hit points left: " << _hit_points << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points == 0)
		std::cout << "ClapTrap " << _name << " is already dead and cannot be repaired" << std::endl;
	
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " has no energy points to be repaired" << std::endl;
	
	else if (_hit_points > 0 && _energy_points > 0)
	{
		_hit_points += amount;
		_energy_points--;
		std::cout << "ClapTrap " << _name << " was repaired. Hit points: " << _hit_points << std::endl;
	}
}