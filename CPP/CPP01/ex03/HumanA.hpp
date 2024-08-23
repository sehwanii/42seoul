/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:44:32 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/18 15:29:52 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP 

#include "Weapon.hpp"

class HumanA{
    private:
        Weapon      &weapon;
        std::string name;
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