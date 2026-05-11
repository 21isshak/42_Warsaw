/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:33:49 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/10 17:16:46 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon&	_weapon;
	public:
	
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		
		void	attack(void);
};

#endif