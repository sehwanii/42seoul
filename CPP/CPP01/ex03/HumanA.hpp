/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:44:32 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/29 10:31:25 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP 

#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon      &weapon;
    public:
        // HumanA();
        // HumanA(std::string name);
        HumanA(std::string name, Weapon& weapon);
		~HumanA();
        void setName(std::string name);
        void setWeapon(Weapon& weapon);

        void    attack();
};

#endif