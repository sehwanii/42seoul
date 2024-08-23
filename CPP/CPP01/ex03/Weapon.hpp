/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:40:47 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/18 15:30:14 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP 

#include <iostream>

class Weapon{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string);
        ~Weapon();
		const std::string   &getType();
        void                setType(std::string type);
};

#endif