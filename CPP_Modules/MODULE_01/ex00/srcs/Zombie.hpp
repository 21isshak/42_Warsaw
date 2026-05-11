/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:31:52 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/09 16:41:45 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <sstream>

class	Zombie {
	
	private:
		std::string _name;
		
	public:
		Zombie(void);
		~Zombie(void);
		Zombie(std::string name);
		
		void	announce(void) const;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif