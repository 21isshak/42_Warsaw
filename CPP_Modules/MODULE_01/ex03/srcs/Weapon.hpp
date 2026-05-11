/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:34:00 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 16:57:44 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <stdio.h>
#include <iostream>

class Weapon {
	private:
		std::string	_type;
	public:
	
		Weapon(void);
		~Weapon(void);
		Weapon(std::string type);
		
		const std::string&	getType(void) const;
		void		setType(std::string type);
};

#endif