/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:59:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/06 20:03:38 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixedValue;						 // Fixed-point number value
	static const int fractionalBits = 8; // Number of fractional bits
public:
	// Default constructor
	Fixed() : fixedValue(0) {}

	// Copy constructor
	Fixed(const Fixed &other) : fixedValue(other.fixedValue) {}

	// Copy assignment operator
	Fixed &operator=(const Fixed &other)
	{
		if (this != &other)
		{ // Self-assignment check
			this->fixedValue = other.fixedValue;
		}
		return *this;
	}

	// Destructor
	~Fixed() {}

	// Get the raw value of the fixed-point number
	int getRawBits(void) const
	{
		return fixedValue;
	}

	// Set the raw value of the fixed-point number
	void setRawBits(int const raw)
	{
		fixedValue = raw;
	}
};

#endif