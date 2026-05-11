/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:39:10 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/28 22:43:47 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {

	private:

	public:
	
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const& copy);
		~ScavTrap();
		
		ScavTrap&	operator=(ScavTrap const& copy);
		
		void	guardGate();
		void	attack(const std::string& target);
};

#endif