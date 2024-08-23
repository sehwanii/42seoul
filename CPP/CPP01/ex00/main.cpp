/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 04:24:20 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/18 15:09:38 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void foo(){
    system("leaks ex00");
}

int main(){
    atexit(foo);
    Zombie zom1("zom1");
    Zombie *zom2 = newZombie("zom2");
    zom1.announce();
    (*zom2).announce();
	randomChump("aaaa");
    delete zom2;
}