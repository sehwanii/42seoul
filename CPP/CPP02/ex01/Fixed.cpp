/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:59:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/22 17:45:38 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixedValue(0) {
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int n) {
	std::cout<<"Default constructor called"<<std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other){
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
	this->setRawBits(other.getRawBits());
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
	{ // Self-assignment check
		this->fixedValue = other.fixedValue;
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout<<"Destructor called"<<std::endl;
}

// Get the raw value of the fixed-point number
int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return fixedValue;
}

// Set the raw value of the fixed-point number
void Fixed::setRawBits(int const raw)
{
	//std::cout<<"setRawBits member function called"<<std::endl;
	fixedValue = raw;
}
