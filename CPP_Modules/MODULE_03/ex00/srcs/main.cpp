/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:04:39 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/28 22:29:32 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	a.attack("Julian");
	a.takeDamage(5);
	a.beRepaired(1);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("a random robot");

	std::cout << std::endl << std::endl;

	ClapTrap b("Bobby");
	for (int i = 0; i < 12; i++) b.attack("Jane");
	b.beRepaired(2);
	b.beRepaired(4);
	
	std::cout << std::endl << std::endl;

	ClapTrap c(b);
	c.attack("Reinhold");
	std::cout << std::endl << std::endl;
	return (0);
}