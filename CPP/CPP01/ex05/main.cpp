/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:44:34 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/09 17:09:33 by sehwjang         ###   ########.fr       */
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