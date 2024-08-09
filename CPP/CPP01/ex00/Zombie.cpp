/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 04:13:14 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/06 20:43:34 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie()
{

}

Zombie:: ~Zombie()
{
	std::cout<<name<<": Gone..."<<std::endl;
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

