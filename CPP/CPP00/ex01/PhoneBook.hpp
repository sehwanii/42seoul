/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 04:37:11 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-04 04:37:11 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP 

# include "Contact.hpp"

class PhoneBook
{
private:
	/* data */
	Contact	mcontact[8];
	int		mlastIdx;
public:
	PhoneBook(/* args */);
	~PhoneBook();
	void	AddContact();
	void	SearchContact();
	void	AddContact(Contact newContact);
	int		GetLastIdx();
	void	PrintContact(int idx);
};

std::string GetInput(std::string str);

#endif