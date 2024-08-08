/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-08 09:03:45 by sehwanii          #+#    #+#             */
/*   Updated: 2024-08-08 09:03:45 by sehwanii         ###   ########kr        */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"


int main()
{
    std::string input;
    Harl harl;
    while (true){
		std::cout << "Please enter the command" << std::endl;
        std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "EOF received, exiting program." << std::endl;
			break;
		}
        harl.complain(input);
    }
}