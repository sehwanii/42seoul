/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-24 08:58:24 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-24 08:58:24 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP 


#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    Weapon* weapon; // 참조에서 포인터로 변경
    std::string name;

public:
    HumanB(std::string name);
    HumanB(std::string name, Weapon& weapon); // Weapon을 참조로 전달
    void setName(std::string name);
    void setWeapon(Weapon& weapon);

    void attack();
};

#endif