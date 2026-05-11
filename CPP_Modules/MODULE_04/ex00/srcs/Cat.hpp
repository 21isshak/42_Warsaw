/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:45 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 15:41:44 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal {
	
	public:
		Cat();
		Cat(Cat const& copy);
		Cat& operator=(Cat const& copy);
		virtual ~Cat();
		
		virtual void	makeSound() const;

};

#endif