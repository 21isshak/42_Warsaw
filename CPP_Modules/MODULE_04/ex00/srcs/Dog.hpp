/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:51 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:41:38 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {
	
	public:
		Dog();
		Dog(Dog const& copy);
		Dog& operator=(Dog const& copy);
		virtual ~Dog();
		
		virtual void	makeSound() const;
	
};

#endif