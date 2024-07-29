/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 04:37:11 by sehwanii          #+#    #+#             */
/*   Updated: 2024/07/29 20:32:45 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP 

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	mcontact[8];
	int		mlastIdx;
public:
	PhoneBook();
	~PhoneBook();
	void	AddContact();
	void	SearchContact();
	void	AddContact(Contact newContact);
	int		GetLastIdx();
	void	PrintContact(int idx);
};

std::string GetInput(std::string str);
std::string GetPhoneNumberInput(std::string str);
bool	CheckPhoneNumberFormat(std::string phonenumber);
void	PrintFormat(std::string str);
#endif