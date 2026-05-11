/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:30:45 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 16:14:29 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
	
	private:
		Brain* brain;
	
	public:
		Cat();
		Cat(Cat const& copy);
		Cat& operator=(Cat const& copy);
		virtual ~Cat();
		
		virtual void	makeSound() const;
		void setIdea(int index, std::string const& idea);
		std::string getIdea(int index) const;

};

#endif