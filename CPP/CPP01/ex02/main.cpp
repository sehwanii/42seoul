/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:23:40 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/18 15:15:56 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

	std::cout<<&str<<std::endl;
    std::cout<<stringPTR<<std::endl;
    std::cout<<&stringREF<<std::endl;

	std::cout<<str<<std::endl;
    std::cout<<*stringPTR<<std::endl;
    std::cout<<stringREF<<std::endl;
}