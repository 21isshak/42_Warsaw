/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:30:59 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 15:10:29 by iskaraag         ###   ########.fr       */
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
		
		void	set_name(std::string name);
		void	announce(void) const;
};

Zombie*	zombieHorde(int N, std::string name);

#endif