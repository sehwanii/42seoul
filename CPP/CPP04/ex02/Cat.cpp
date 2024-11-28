/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:19:53 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/29 10:55:22 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : type("Cat"), brain(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : type(other.type)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout<< "Cat Copy assignment operator called"<<std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
    std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const{
	std::cout << "MEOW MEOW!" << std::endl;
}

std::string Cat::getType(void) const{
	return this->type;
}