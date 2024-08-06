/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 04:43:48 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/06 16:40:54 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
	for(int i = 0; i < 8; i++)	
		this->mcontact[i].SetUsing(false);
}

PhoneBook::~PhoneBook()
{

}

void    PhoneBook::Add()
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
    phone_number = GetPhoneNumberInput( "Phone Number? (010-xxxx-xxxx)\n");
    darkest_secret = GetInput("Darkest Secret?\n");
    newContact.SetContact(first_name, last_name, nickname, phone_number, darkest_secret);
    AddContact(newContact);
	this->mlastIdx = (this->mlastIdx + 1) % 8;
}



void PhoneBook::SearchContact()
{
    int userIdx;
	int	flag = 0;
    std::string userInput;
	std::cout<<"|     Index|First Name| Last Name|  Nickname|"<<std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (mcontact[i].GetUsing() == true){
            PrintContact(i);
			flag++;
		}
    }
	if (flag == 0){
		std::cout << "nothing to search" << std::endl;
		return ;
	}

    std::cout << "Enter index?" << std::endl;
    std::getline(std::cin, userInput);
    while (userInput.length() != 1 || userInput[0] < '0' || userInput[0] > flag - 1 + '0' || !isdigit(userInput[0]))
    {
        std::cout << "Wrong Index (0 ~ " << flag - 1 <<")" << std::endl;
        std::getline(std::cin, userInput);
    }
	std::cout<<"First Name     : "<<mcontact[userInput[0] - '0'].GetFirstName()<<std::endl;
	std::cout<<"Last Name      : "<<mcontact[userInput[0] - '0'].GetLastName()<<std::endl;
	std::cout<<"Nickname       : "<<mcontact[userInput[0] - '0'].GetNickname()<<std::endl;
	std::cout<<"Phone Number   : "<<mcontact[userInput[0] - '0'].GetPhoneNumber()<<std::endl;
	std::cout<<"Darkest Secret : "<<mcontact[userInput[0] - '0'].GetDarkestSecret()<<std::endl;

}

void	PhoneBook::PrintContact(int idx)
{
    const std::string first_name = mcontact[idx].GetFirstName();
    const std::string last_name = mcontact[idx].GetLastName();
    const std::string nickname = mcontact[idx].GetNickname();
	std::cout<<"|"<<std::setw(10)<<idx;
	PrintFormat(first_name);
	PrintFormat(last_name);
	PrintFormat(nickname);
    std::cout<<"|"<<std::endl;
}

void	PhoneBook::AddContact(Contact newContact)
{
    const int next_idx = (GetLastIdx()) % 8;

    mcontact[next_idx] = newContact;
    return ;
}

int     PhoneBook::GetLastIdx()
{
    return (mlastIdx);
}

bool contains_nonprintable(const std::string& s)
{
    for (std::string::const_iterator it = s.begin(); it != s.end(); ++it)
    {
        if (!std::isprint(*it))
        {
            return true;
        }
    }
    return false;
}

std::string GetInput(std::string str)
{
    std::string ret_str;

    std::cout << str;
	std::getline(std::cin, ret_str);
	if (std::cin.eof()) {
		std::cout << "EOF received, exiting program." << std::endl;
		exit(1);
	}
    while (ret_str.empty() || contains_nonprintable(ret_str))
    {
        if (ret_str.empty())
        {
            std::cout << "Input cannot be empty. Please enter again: ";
        }
        else
        {
            std::cout << "Non-printable characters detected. Please enter again: ";
        }

        std::getline(std::cin, ret_str);
        if (std::cin.eof())
        {
            std::cout << "EOF received, exiting program." << std::endl;
            exit(1);
        }
    }
    return (ret_str);
}

std::string GetPhoneNumberInput(std::string str)
{
    std::string ret_str = "";

    std::cout << str;
    std::getline(std::cin, ret_str);
    while (!CheckPhoneNumberFormat(ret_str))
    {
        std::cout << "Wrong Format! (010-xxxx-xxxx)" << std::endl;
        std::getline(std::cin, ret_str);
    }
    return (ret_str);
}

bool	CheckPhoneNumberFormat(std::string phonenumber)
{
	if (phonenumber.length() != 13 || phonenumber.substr(0, 3) != "010") {
        return false;
    }
    if (phonenumber[3] != '-' || phonenumber[8] != '-') {
        return false;
    }
    for (int i = 0; i < 13; i++) {
        if (i == 3 || i == 8) {
            continue;
        }
        if (phonenumber[i] < '0' || phonenumber[i] > '9') {
            return false;
        }
    }
    return true;
}

void	PrintFormat(std::string str)
{
	if (str.length() > 10)
		std::cout<<"|"<<str.substr(0,9)<<'.';
	else
		std::cout<<"|"<<std::setw(10)<<str;
}
