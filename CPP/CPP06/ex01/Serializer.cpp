/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:25:15 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 18:26:45 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = other;
}

Serializer::~Serializer()
{
	std::cout << "Serializer Deconstructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other)
{
	std::cout << "Serializer Assignation operator called" << std::endl;
	if (this == &other)
		return *this;

	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}