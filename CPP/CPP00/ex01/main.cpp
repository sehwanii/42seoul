/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 06:34:51 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/05 18:12:57 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    std::string input;
    PhoneBook   phonebook;

    while (true){
		std::cout << "Please enter the command" << std::endl;
		std::cin.clear();
        std::getline(std::cin, input);
		if (std::cin.eof()) { // EOF 입력인지 확인
			std::cout << "EOF received, exiting program." << std::endl;
			break; // 루프 종료
		}
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