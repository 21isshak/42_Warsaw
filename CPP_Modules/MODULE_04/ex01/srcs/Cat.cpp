/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:43 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 16:15:45 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new(Brain))
{
	_type = "Cat";
	std::cout << "Cat is constructed" << std::endl;
}

Cat::Cat(Cat const& copy) : Animal(copy), brain(new Brain(*copy.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat&	Cat::operator=(Cat const& copy)
{
	std::cout << "Cat assignment operator overload called" << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << _type << " is destructed" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MEOOOOOOOW!" << std::endl;
}

void Cat::setIdea(int index, std::string const& idea)
{
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return brain->getIdea(index);
}