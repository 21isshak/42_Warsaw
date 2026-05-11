/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:51:46 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/11 20:26:26 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	std::cout << "\nincrementions" << std::endl;
	Fixed a;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	
	std::cout << "\narithmetic operators" << std::endl;
	std::cout << (Fixed( 5.05f ) * Fixed( 2 )) << std::endl;
	std::cout << Fixed( 5.05f ) + Fixed( 2 ) << std::endl;
	std::cout << Fixed( 5.05f ) - Fixed( 2 ) << std::endl;
	std::cout << Fixed( 5.05f ) / Fixed( 2 ) << std::endl;
	
	std::cout << "\ncomparison operators" << std::endl;
	std::cout << (Fixed( 5.05f ) != Fixed( 2 )) << std::endl;
	std::cout << (Fixed( 5.05f ) == Fixed( 2 )) << std::endl;
	
	std::cout << "\nmax-min" << std::endl;
	Fixed b = 3.05078f;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	
	return 0;
}