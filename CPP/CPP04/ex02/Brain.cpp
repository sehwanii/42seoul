/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-28 18:45:22 by sehwanii          #+#    #+#             */
/*   Updated: 2024-11-28 18:45:22 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = i;
    }
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = other.ideas[i]; // 다른 Brain 객체의 아이디어 복사
    }
    std::cout << "Brain copy constructor called" << std::endl;
}

// 복사 대입 연산자
Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = other.ideas[i]; // 다른 Brain 객체의 아이디어 복사
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}