/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-28 18:33:36 by sehwanii          #+#    #+#             */
/*   Updated: 2024-11-28 18:33:36 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	std::string type;
	Brain*      brain;

public:
	Dog(void);
	Dog(const Dog &obj);
	Dog &operator=(const Dog &obj);
	virtual ~Dog(void);
	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif