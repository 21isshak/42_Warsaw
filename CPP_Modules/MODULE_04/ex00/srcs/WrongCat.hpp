/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:08:12 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:38:34 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	
	public:
		WrongCat();
		WrongCat(WrongCat const& copy);
		WrongCat& operator=(WrongCat const& copy);
		virtual ~WrongCat();
		
		void	makeSound() const;

};

#endif