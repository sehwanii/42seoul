/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-24 04:24:20 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-24 04:24:20 by sehwanii         ###   ########.fr       */
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
    delete zom2;
}