/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 08:38:05 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/29 10:54:27 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    

    std::cout << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    std::cout << j->getType() << " " << std::endl;
    j->makeSound();
    std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
    std::cout << std::endl;

   

    std::cout << std::endl;
    delete meta;
    meta = NULL;
    delete j;
    j = NULL;
    delete i;
    i = NULL;

	

	// const WrongAnimal *meta2 = new WrongAnimal();
    // const WrongAnimal *k = new WrongCat();
    

    // std::cout << std::endl;
    // std::cout << k->getType() << " " << std::endl;
    // k->makeSound();
    // std::cout << meta2->getType() << " " << std::endl;
    // meta2->makeSound();
    // std::cout << std::endl;

   

    // std::cout << std::endl;
    // delete meta2;
    // meta2 = NULL;
    // delete k;
    // k = NULL;

    return 0;
}