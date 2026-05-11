/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:43:49 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 16:21:02 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\x1B[34mBrain is constructed\033[0m" << std::endl;
}

Brain::Brain(Brain const& copy)
{
	std::cout << "\x1B[34mBrain copy constructed\033[0m" << std::endl;
	for (int i = 0; i < 100; ++i)
		ideas[i] = copy.ideas[i];
}

Brain& Brain::operator=(Brain const& copy)
{
	std::cout << "\x1B[34mBrain assigment copy called\033[0m" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = copy.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "\x1B[34mBrain is destructed\033[0m" << std::endl;
}

void	Brain::setIdea(int index, std::string const& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ("\x1B[1;34m"+ideas[index]+"\033[0m");
	return ("\x1B[34mINVALID_INDEX\033[0m");
}