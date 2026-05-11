/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:48 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 16:53:20 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new(Brain))
{
	_type = "Dog";
	std::cout << "Dog is constructed" << std::endl;
}

Dog::Dog(Dog const& copy) : AAnimal(copy), brain(new Brain(*copy.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog&	Dog::operator=(Dog const& copy)
{
	std::cout << "Dog assignment operator overload called" << std::endl;
	if (this != &copy)
	{
		_type = copy._type;
		delete brain;
		brain = new Brain(*copy.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << _type << " is destructed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "WUFF! WUFF! WUFF!" << std::endl;
}

void Dog::setIdea(int index, std::string const& idea)
{
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return brain->getIdea(index);
}