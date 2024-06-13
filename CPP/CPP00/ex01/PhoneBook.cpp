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
    first_name = GetInput("First Name?\n");
    last_name = GetInput("Last Name?\n");
    nickname = GetInput("Nickame?\n");
    phone_number = GetInput( "Phone Number? (010-xxxx-xxxx)\n");
    darkest_secret = GetInput("Darkest Secret?\n");
    newContact.SetContact(first_name, last_name, nickname, phone_number, darkest_secret);
    AddContact(newContact);
}



void    PhoneBook::SearchContact()
{
    int userIdx;

    for (int i = 0 ; i < 8 ; i++){
        PrintContact(i);
    }
    std::cout << "Which \n";
    std::cin >> userIdx;

}

void	PhoneBook::PrintContact(int idx)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout<<"|";
    first_name = mcontact[idx].GetFirstName();
    std::cout.width(9);
    std::cout<<first_name;
    // if (first_name.length() <= 9){
    //     for (int i )
    // }
    std::cout<<"|";

    std::cout<<"|";

    std::cout<<"|";

    std::cout<<"|";
}

void	PhoneBook::AddContact(Contact newContact)
{
    const int next_idx = (GetLastIdx() + 1) % 8;

    mcontact[next_idx] = newContact;
    return ;
}

int     PhoneBook::GetLastIdx()
{
    return (mlastIdx);
}

std::string GetInput(std::string str)
{
    std::string ret_str = "";

    std::cout << str;
    while (ret_str == "")
        std::cin >> ret_str;
    return (ret_str);
}