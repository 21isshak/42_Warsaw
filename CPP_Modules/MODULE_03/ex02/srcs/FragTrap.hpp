/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:11:02 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/29 18:25:37 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {

	private:
	
	public:
	
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const& copy);
		~FragTrap();

		FragTrap& operator=(FragTrap const& copy);
		
		void	highFivesGuys(void);
		void	attack(const std::string& target);
};

#endif