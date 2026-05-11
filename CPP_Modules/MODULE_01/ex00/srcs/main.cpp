/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:31:30 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 14:27:58 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack1("Stack1");
	Zombie	stack2("Stack2");
	stack1.announce();
	stack2.announce();
	std::cout << std::endl;
	
	Zombie*	heap1 = newZombie("Heap2");
	Zombie*	heap2 = newZombie("Heap1");
	heap2->announce();
	heap1->announce();
	std::cout << std::endl;
	
	randomChump("Random Chump");
	std::cout << std::endl;
	
	delete(heap1);
	delete(heap2);

	return (0);
}
