/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:51:41 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/19 20:59:28 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int	_value;
		static const int	_fractional_bits;
	
	public:
		Fixed();
		Fixed(Fixed const& copy);
		Fixed& operator=(Fixed const& cpy);
		~Fixed();

		
		int		getRawBits(void) const;
		void	setRawBits(int const val);
};

#endif
