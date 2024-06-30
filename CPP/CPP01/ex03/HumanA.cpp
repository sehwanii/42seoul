/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-24 08:44:22 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-24 08:44:22 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

// HumanA::HumanA(){

// }

// HumanA::HumanA(std::string name){
//     setName(name);
// }

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::setName(std::string name){
    this->name = name;
}

void HumanA::setWeapon(Weapon& weapon){
    this->weapon = weapon;
}

void HumanA::attack()
{
    std::cout << this->name<<" attacks with their "<<this->weapon.getType()<<std::endl;
}