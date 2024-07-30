/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 06:34:51 by sehwanii          #+#    #+#             */
/*   Updated: 2024/07/29 21:12:06 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    std::string input;
    PhoneBook   phonebook;

	phonebook.SetPhoneBook();
    while (true){
		std::cout << "Please enter the command" << std::endl;
        std::cin >> input;
        if (input == "ADD")
            phonebook.Add();
        else if (input == "SEARCH")
            phonebook.SearchContact();
        else if (input == "EXIT")
            exit(0);
        else
            std::cout << "Wrong Command\n";
    }
}