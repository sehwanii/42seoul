/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:59:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/23 10:59:39 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0) {
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
	this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
	{ // Self-assignment check
		this->fixedValue = other.fixedValue;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return fixedValue;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout<<"setRawBits member function called"<<std::endl;
	fixedValue = raw;
}
