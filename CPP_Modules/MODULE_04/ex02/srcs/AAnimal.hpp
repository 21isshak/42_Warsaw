/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:41 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 16:29:15 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class	AAnimal {
	
	protected:
		std::string	_type;
		
	public:
		AAnimal();
		AAnimal(AAnimal const& copy);
		AAnimal& operator=(AAnimal const& copy);
		virtual ~AAnimal();
		
		virtual void	makeSound() const = 0;
		std::string	getType() const;

};

#endif