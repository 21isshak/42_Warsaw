/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:51 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 16:14:21 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal {
	
	private:
		Brain* brain;
	
	public:
		Dog();
		Dog(Dog const& copy);
		Dog& operator=(Dog const& copy);
		virtual ~Dog();
		
		virtual void	makeSound() const;
		void setIdea(int index, std::string const& idea);
		std::string getIdea(int index) const;
	
};

#endif