/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:30:52 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 15:10:39 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* horde = zombieHorde(4, "iso");
	for (int i = 0; i < 4; i++)
	{
		std::cout << i << " ";
		horde[i].announce();
	}
	
	delete[] horde;
	
	return (0);
}