/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 07:20:28 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-04 07:20:28 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){

}

Contact::~Contact(){
    
}

void    Contact::SetContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
    this->mfirst_name = first_name;
    this->mlast_name = last_name;
    this->mnickname = nickname;
    this->mphone_number = phone_number;
    this->mdarkest_secret = darkest_secret;
}