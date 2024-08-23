/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:59:51 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/23 14:08:37 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) : fixedValue(integer << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatingPoint) : fixedValue(static_cast<int>(roundf(floatingPoint * (1 << fractionalBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{ // Self-assignment check
		this->fixedValue = other.fixedValue;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedValue;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout<<"setRawBits member function called"<<std::endl;
	fixedValue = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedValue) / (1 << fractionalBits);
}
int Fixed::toInt(void) const
{
	return fixedValue >> fractionalBits;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.toFloat() == 0)
	{
		std::cerr << "Division by zero is undefined." << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->fixedValue == other.fixedValue;
}
bool Fixed::operator>=(const Fixed &other) const
{
	return this->fixedValue >= other.fixedValue;
}
bool Fixed::operator<=(const Fixed &other) const
{
	return this->fixedValue <= other.fixedValue;
}
bool Fixed::operator>(const Fixed &other) const
{
	return this->fixedValue > other.fixedValue;
}
bool Fixed::operator<(const Fixed &other) const
{
	return this->fixedValue < other.fixedValue;
}
bool Fixed::operator!=(const Fixed &other) const
{
	return this->fixedValue != other.fixedValue;
}

Fixed &Fixed::operator++(void) {
    this->fixedValue++;
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}
Fixed &Fixed::operator--(void) {
    this->fixedValue--;
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { 
	return (a.fixedValue < b.fixedValue) ? a : b; 
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.fixedValue < b.fixedValue) ? a : b; 
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a.fixedValue > b.fixedValue) ? a : b; 
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.fixedValue > b.fixedValue) ? a : b; 
}
