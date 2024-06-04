/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 06:34:51 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-04 06:34:51 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    std::string input;
    PhoneBook   phonebook;

    while (true){
        std::cin >> input;
        if (input == "ADD")
            phonebook.Add();
        else if (input == "SEARCH")
            phonebook.Search();
        else if (input == "EXIT")
            exit(0);
        else
            std::cout << "Wrong Command\n";
    }
}