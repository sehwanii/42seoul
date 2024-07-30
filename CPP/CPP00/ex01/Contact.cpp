/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 07:20:28 by sehwanii          #+#    #+#             */
/*   Updated: 2024/07/29 21:14:19 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){

}

Contact::~Contact(){
    
}

void    Contact::SetContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->musing = true;
    this->mfirst_name = first_name;
    this->mlast_name = last_name;
    this->mnickname = nickname;
    this->mphone_number = phone_number;
    this->mdarkest_secret = darkest_secret;
}

std::string	Contact::GetFirstName(){
	return (mfirst_name);
}

std::string	Contact::GetLastName(){
	return (mlast_name);
}

std::string	Contact::GetNickame(){
	return (mnickname);
}

std::string	Contact::GetPhoneNumber(){
	return (mphone_number);
}

std::string	Contact::GetDarkestSecret(){
	return (mdarkest_secret);
}

bool	Contact::GetUsing(){
	return (musing);
}

void	Contact::SetUsing(bool status){
	this->musing = status;
}