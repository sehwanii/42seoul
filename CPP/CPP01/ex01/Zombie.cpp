/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-24 04:13:14 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-24 04:13:14 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie()
{

}

Zombie:: ~Zombie()
{

}

Zombie:: Zombie(std::string name)
{
    Zombie::name = name;
    return ;
}

void Zombie::announce(void)
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ...\n";
    return ;
}

