/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:41:16 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 18:46:42 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base
{
public:
	virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif