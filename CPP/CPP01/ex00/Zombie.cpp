/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 04:13:14 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/18 15:12:11 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie()
{

}

Zombie:: ~Zombie()
{
	std::cout<<name<<": Bye..."<<std::endl;
}

Zombie:: Zombie(std::string name)
{
    Zombie::name = name;
    return ;
}

void Zombie::announce(void)
{
    std::cout<<name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
    return ;
}

