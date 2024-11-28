/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-28 18:37:18 by sehwanii          #+#    #+#             */
/*   Updated: 2024-11-28 18:37:18 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
    std::string ideas[100];

public:
    Brain(void);
    Brain(const Brain &obj);
    Brain &operator=(const Brain &obj);
    virtual ~Brain(void);
};

#endif