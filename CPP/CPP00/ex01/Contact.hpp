/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-04 04:37:07 by sehwanii          #+#    #+#             */
/*   Updated: 2024-06-04 04:37:07 by sehwanii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP 

# include <iostream>

class Contact
{
private:
    /* data */
    int idx;
    std::string mfirst_name;
    std::string mlast_name;
    std::string mnickname;
    std::string mphone_number;
    std::string mdarkest_secret;

public:
    Contact(/* args */);
    ~Contact();
    void    SetContact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
};

#endif