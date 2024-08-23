/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:59:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/09 18:47:25 by sehwjang         ###   ########.fr       */
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
	Fixed();

	// Copy constructor
	Fixed(const Fixed &other);

	// Copy assignment operator
	Fixed &operator=(const Fixed &other);

	// Destructor
	~Fixed();

	// Get the raw value of the fixed-point number
	int getRawBits(void) const;

	// Set the raw value of the fixed-point number
	void setRawBits(int const raw);
};

#endif
