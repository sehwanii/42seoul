/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-28 18:33:29 by sehwanii          #+#    #+#             */
/*   Updated: 2024-11-28 18:33:29 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include <iostream>
#include "Animal.hpp"
class Cat : public Animal
{
private:
    std::string type;

public:
    Cat(void);
    Cat(const Cat &obj);
    Cat &operator=(const Cat &obj);
    virtual ~Cat(void);
    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif