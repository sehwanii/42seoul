/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:58:24 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/06 19:18:06 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP 


#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
    Weapon* weapon;
    std::string name;

public:
    HumanB(std::string name);
    HumanB(std::string name, Weapon& weapon);
    void setName(std::string name);
    void setWeapon(Weapon& weapon);

    void attack();
};

#endif