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
    system("leaks ex01");
}

int main(){
    atexit(foo);
    
    Zombie *zombies = zombieHorde(10, "zombies!");
    for (int i = 0; i < 10 ; i++)
        zombies[i].announce();
    delete[] zombies;
}