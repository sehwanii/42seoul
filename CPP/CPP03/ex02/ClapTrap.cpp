/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-12 05:11:15 by sehwanii          #+#    #+#             */
/*   Updated: 2024-08-12 05:11:15 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : mName("default"), mHitPoint(10), mEnergyPoint(10), mAttackDamage(0) {
    std::cout << "ClapTrap " << mName << " constructor called" << std::endl;
}


ClapTrap::ClapTrap(std::string name) : mName(name)
{
    this->mAttackDamage = 0;
    this->mHitPoint = 10;
    this->mEnergyPoint = 10;

    std::cout << "ClapTrap "<<this->mName<<" constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->mName = other.mName;
    this->mAttackDamage = other.mAttackDamage;
    this->mEnergyPoint = other.mEnergyPoint;
    this->mHitPoint = other.mHitPoint;

    std::cout << "ClapTrap " << this->mName << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->mName << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (mEnergyPoint <= 0)
    {
        std::cout << "No Energy..." << std::endl;
        return ;
    }
    else if (mHitPoint <= 0)
    {
        std::cout << "No Hit Point..." << std::endl;
        return ;
    }
    std::cout <<mName <<" attacks "<<target<<" with "<<mAttackDamage<<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (mHitPoint - amount < 0)
        mHitPoint = 0;
    else
        mHitPoint -= amount;
    std::cout <<mName<<" has taken "<<amount<<" damage"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (mEnergyPoint <= 0)
    {
        std::cout << "No Energy..." << std::endl;
        return ;
    }
    else if (mHitPoint <= 0)
    {
        std::cout << "No Hit Point..." << std::endl;
        return ;
    }
    this->mHitPoint += amount;
    std::cout <<mName<<" has been repaired "<<amount <<" Hit Point"<<std::endl;
}