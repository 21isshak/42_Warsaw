/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:43:53 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/05 16:08:53 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain {
	
	private:
		std::string	ideas[100];
	
	public:
		Brain();
		Brain(Brain const& copy);
		Brain& operator=(Brain const& copy);
		~Brain();
		
		void	setIdea(int index, std::string const& idea);
		std::string	getIdea(int index) const;
};

#endif