/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:08:07 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:37:32 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal {
	
	protected:
		std::string	_type;
	
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const& copy);
		WrongAnimal& operator=(WrongAnimal const& copy);
		virtual ~WrongAnimal();
		
		void	makeSound() const;
		std::string	getType() const;
};

#endif