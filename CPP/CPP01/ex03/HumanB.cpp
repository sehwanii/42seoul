/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:10:02 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/29 10:32:28 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) {

}
HumanB::~HumanB() {}
HumanB::HumanB(std::string name, Weapon& weapon) : name(name), weapon(&weapon) {}

void HumanB::setName(std::string name) {
    this->name = name;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

void HumanB::attack() {
    if (this->weapon) {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    } else {
        std::cout << this->name << " has no weapon" << std::endl;
    }
}