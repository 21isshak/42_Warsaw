/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:10:59 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/29 18:25:23 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "\x1B[32mFragTrap " << _name << " default constucter called\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
	std::cout << "\x1B[32mFragTrap " << _name << " is constucted\033[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const& copy)
{
	std::cout << "\x1B[32mFragTrap " << "copy constructor called\033[0m" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap()
{
	std::cout << "\x1B[32mFragTrap: " << _name << " was destructed\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const& copy)
{
	std::cout << "\x1B[32mAssignment operator called\033[0m" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hit_points = copy._hit_points;
		_energy_points = copy._energy_points;
		_attack_damage = copy._attack_damage;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "\x1B[32mHEY, its " << _name << " HIGHFIVES. Shall we?\033[0m" << std::endl;
}

void	FragTrap::attack(const std::string & target)
{
	if (_hit_points == 0)
		std::cout << "\033[3;47;31mFragTrap " << _name << " is dead and cannot attack " << target << "\033[0m" << std::endl;
	else if (_energy_points == 0)
		std::cout << "\033[3;47;31mFragTrap " << _name << " has no energy points to attack " << target << "\033[0m" << std::endl;
	else if (_energy_points > 0 && _hit_points > 0)
	{
		std::cout << "\033[3;47;31mFragTrap " << _name << " attacks " << target << " causing " << _attack_damage << " damage\033[0m" << std::endl;
		_energy_points--;
	}
}
