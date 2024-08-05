/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 04:43:48 by sehwanii          #+#    #+#             */
/*   Updated: 2024/08/05 18:15:50 by sehwjang         ###   ########.fr       */
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



void    PhoneBook::SearchContact()
{
    int userIdx;
	std::string userInput;

    for (int i = 0 ; i < 8 ; i++){
		//std::cout << mcontact[i].GetUsing();
		if (mcontact[i].GetUsing() == true)
	        PrintContact(i);
    }
    std::cout << "Enter index?" << std::endl;
    std::cin >> userInput;
	while (userInput.length() != 1 || userInput[0] < '0' || userInput[0] > '9'){
		std::cout << "Wrong Index (1 ~ 8)" << std::endl;
		std::cin >> userInput;
	}

	//ㅁㄴㅇㄹㅁㄴㅇㄹ

}

void	PhoneBook::PrintContact(int idx)
{
    const std::string first_name = mcontact[idx].GetFirstName();
    const std::string last_name = mcontact[idx].GetLastName();
    const std::string nickname = mcontact[idx].GetNickame();
    //const std::string phone_number = mcontact[idx].GetPhoneNumber();
    //const std::string darkest_secret = mcontact[idx].GetDarkestSecret();
	std::cout<<"|"<<std::setw(10)<<idx;
	PrintFormat(first_name);
	PrintFormat(last_name);
	PrintFormat(nickname);
	//PrintFormat(phone_number);
	//PrintFormat(darkest_secret);
    std::cout<<"|"<<std::endl;
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
	std::getline(std::cin, ret_str);
		if (std::cin.eof()) { // EOF 입력인지 확인
			std::cout << "EOF received, exiting program." << std::endl;
			exit(1); // 루프 종료
		}
    // while (ret_str == "")
    //     std::cin >> ret_str;
    return (ret_str);
}

std::string GetPhoneNumberInput(std::string str)
{
	std::string ret_str = "";

    std::cout << str;
	std::cin >> ret_str;
    while (!CheckPhoneNumberFormat(ret_str)){
		std::cout << "Wrong Format! (010-xxxx-xxxx)" << std::endl;
        std::cin >> ret_str;
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
