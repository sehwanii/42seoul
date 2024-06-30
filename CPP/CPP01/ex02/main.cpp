/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-24 08:23:40 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-24 08:23:40 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout<<stringPTR<<std::endl;
    std::cout<<&stringREF<<std::endl;

    std::cout<<*stringPTR<<std::endl;
    std::cout<<stringREF<<std::endl;
}