/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:30:15 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/29 10:32:56 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){

}
Weapon::~Weapon(){}
Weapon::Weapon(std::string type){
    setType(type);
}

const std::string &Weapon::getType()
{
    return (this->type);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
    return ;
}