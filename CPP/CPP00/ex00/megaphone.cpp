/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 04:37:19 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-04 04:37:19 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void  printupper(std::string str)
{
    for (int i = 0; i < str.length();i++){
        std::cout << (unsigned char)toupper(str[i]);
    }
}

int main(int argc, char* argv[])
{
    if (argc == 1){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    else{
        for (int i = 1; i < argc; i++){
            printupper(argv[i]);
        }
        std::cout << "\n";
    }
}