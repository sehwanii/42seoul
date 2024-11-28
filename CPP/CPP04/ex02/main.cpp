/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-28 18:34:24 by sehwanii          #+#    #+#             */
/*   Updated: 2024-11-28 18:34:24 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(){
    const Animal *animals[10];
    //const Animal = Animal();
    for(int i = 0; i<10; i++){
        if (i%2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for(int i = 0; i<10;i++){
        delete animals[i];
    }
    system("leaks ex02");
    return 0;
}