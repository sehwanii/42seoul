/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 04:43:48 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-04 04:43:48 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void    PhoneBook::AddContact()
{
    Contact newContact;
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Adding New information\n";
    std::cout << "First Name?\n";
    std::cin >> first_name;
    std::cout << "Last Name?\n";
    std::cin >> last_name;
    std::cout << "Nickname?\n";
    std::cin >> nickname;
    std::cout << "Phone Number? (010-xxxx-xxxx)\n";
    std::cin >> phone_number;
    std::cout << "Darkest Secret?\n";
    std::cin >> darkest_secret;
    newContact.SetContact(first_name, last_name, nickname, phone_number, darkest_secret);
    AddContact(newContact);
}

void    PhoneBook::SearchContact()
{

}

void	AddContact(Contact newContact)
{
    
}