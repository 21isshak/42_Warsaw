/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:51:41 by iskaraag          #+#    #+#             */
/*   Updated: 2025/07/20 14:33:43 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int	_value;
		static const int	_fractional_bits;
	
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(Fixed const& copy);
		Fixed& operator=(Fixed const& cpy);
		~Fixed();

		
		int		getRawBits(void) const;
		void	setRawBits(int const val);
		float	toFloat(void) const;
		int		toInt(void) const;
};

	std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num);

#endif