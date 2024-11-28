/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 06:10:21 by sehwanii          #+#    #+#             */
/*   Updated: 2024/11/29 01:31:54 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("A");
	ClapTrap b("B");

	a.attack("B");
	b.takeDamage(5);//5
	b.beRepaired(3);//8
	b.attack("A");
	a.takeDamage(9);//1
	//a.takeDamage(10);//0
	a.beRepaired(10);//o
	return (0);
}