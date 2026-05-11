/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:51:41 by iskaraag          #+#    #+#             */
/*   Updated: 2025/08/11 20:16:10 by iskaraag         ###   ########.fr       */
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
		~Fixed();
		//operation overload
		Fixed& operator=(Fixed const& cpy);

		//getter&setter
		int		getRawBits(void) const;
		void	setRawBits(int const val);
		//convertion functions
		float	toFloat(void) const;
		int		toInt(void) const;
		
		//comparison operators
		bool operator>(Fixed var) const;
		bool operator<(Fixed var) const;
		bool operator>=(Fixed var) const;
		bool operator<=(Fixed var) const;
		bool operator==(Fixed var) const;
		bool operator!=(Fixed var) const;
		
		//arithmetic operators
		float operator+(Fixed var) const;
		float operator-(Fixed var) const;
		float operator*(Fixed var) const;
		float operator/(Fixed var) const;
		
		//post increment operators
		Fixed operator++(int);
		Fixed operator--(int);
		//pre increment operators
		Fixed operator++(void);
		Fixed operator--(void);
		
		static Fixed& max(Fixed& a, Fixed& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed const& min(Fixed const& a, Fixed const& b);
		
};
	//ostream overload
	std::ostream& operator<<(std::ostream& os, const Fixed& fixed_num);

#endif