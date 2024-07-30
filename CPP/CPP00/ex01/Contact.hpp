/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 04:37:07 by sehwanii          #+#    #+#             */
/*   Updated: 2024/07/29 21:14:28 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP 

# include <iostream>

class Contact
{
private:
	int 	midx;
	bool	musing;
    std::string mfirst_name;
    std::string mlast_name;
    std::string mnickname;
    std::string mphone_number;
    std::string mdarkest_secret;

public:
    Contact();
    ~Contact();
    void    SetContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
    void	SetUsing(bool status);
	std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickame();
    std::string GetPhoneNumber();
    std::string GetDarkestSecret();
	bool		GetUsing();
};

#endif