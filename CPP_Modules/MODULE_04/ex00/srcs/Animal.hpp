/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:41 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:36:36 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal {
	
	protected:
		std::string	_type;
		
	public:
		Animal();
		Animal(Animal const& copy);
		virtual ~Animal();
		
		Animal& operator=(Animal const& copy);
		
		virtual void	makeSound() const;
		std::string	getType() const;

};

#endif