/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:43:46 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/16 13:52:04 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

class	Harl{
	
	private:
		void _debug( void );
		void _info( void );
		void _warning( void );
		void _error( void );
	
	public:
		Harl(void);
		~Harl(void);
		void complain( std::string level );
};

#endif