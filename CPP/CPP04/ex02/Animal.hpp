/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-28 18:33:20 by sehwanii          #+#    #+#             */
/*   Updated: 2024-11-28 18:33:20 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;

public:
    Animal(void);
    Animal(const Animal &obj);
    Animal &operator=(const Animal &obj);
    virtual ~Animal(void);

    virtual void makeSound(void) const = 0;

    virtual std::string getType(void) const;
};

#endif