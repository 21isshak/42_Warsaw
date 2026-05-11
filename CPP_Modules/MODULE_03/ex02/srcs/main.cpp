/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:04:39 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/29 18:25:29 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap harry("Harry");
	ClapTrap hermione("Hermione");
	ClapTrap ron("Ron");
	ScavTrap hagrid("Hagrid");
	FragTrap ben("Ben");

	harry.attack("Voldemort");
	harry.attack("Malfoy");
	harry.attack("Draco");
	harry.takeDamage(5);
	hermione.takeDamage(9);
	hermione.takeDamage(10);
	ron.beRepaired(10);
	ron.takeDamage(19);
	hagrid.attack("Voldemort");
	hagrid.takeDamage(99);
	hagrid.beRepaired(50);
	hagrid.guardGate();
	ben.attack("Voldemort");
	ben.takeDamage(89);
	ben.beRepaired(72);
	ben.highFivesGuys();
	return (0); 
}