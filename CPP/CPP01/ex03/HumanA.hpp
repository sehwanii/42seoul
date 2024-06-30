/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-24 08:44:32 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-24 08:44:32 by sehwanii         ###   ########.fr       */
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
        void setName(std::string name);
        void setWeapon(Weapon& weapon);

        void    attack();
};

#endif