/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:33:53 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 17:17:13 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B

#include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon* _weapon;
		
	public:
	
		HumanB(std::string name);
		~HumanB(void);
		
		void	attack(void);
		void	setWeapon(Weapon& weapon);
};

#endif