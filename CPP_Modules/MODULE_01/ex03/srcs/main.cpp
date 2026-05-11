/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:33:55 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 17:20:08 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		//Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		//jim.setWeapon(club);
		jim.attack();
		//club.setType("some other type of club");
		//jim.attack();
	}
	return 0;
}