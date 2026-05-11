/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:04:36 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/28 22:30:44 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	
	private:
		std::string	_name;
		int	_hit_points;
		int	_energy_points;
		int _attack_damage;

	public:
	
		ClapTrap();
		ClapTrap(std::string const& name);
		ClapTrap(ClapTrap const& copy);
		ClapTrap& operator=(ClapTrap const& copy);
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif