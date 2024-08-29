/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:44:22 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/29 10:32:18 by sehwjang         ###   ########.fr       */
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
HumanA::~HumanA() {}
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