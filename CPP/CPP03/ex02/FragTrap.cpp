/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-12 06:24:41 by sehwanii          #+#    #+#             */
/*   Updated: 2024-08-12 06:24:41 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() {
    mName = "default";    
    mHitPoint = 100;
    mEnergyPoint = 50;
    mAttackDamage = 20;
    std::cout << "FragTrap " << mName << " constructor called" << std::endl;
}


FragTrap::FragTrap(std::string name){
    this->mName = name;
    this->mHitPoint = 100;
    this->mEnergyPoint = 50;
    this->mAttackDamage = 20;
    std::cout << "FragTrap "<<name<<" constructor called"<<std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap "<<this->mName<<" destructor called"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
{
    this->mName = other.mName;
    this->mAttackDamage = other.mAttackDamage;
    this->mEnergyPoint = other.mEnergyPoint;
    this->mHitPoint = other.mHitPoint;

    std::cout << "FragTrap " << this->mName << " constructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout<<mName<<" high fives with guys~"<<std::endl;
}

void FragTrap::attack(const std::string &target)
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
    std::cout	<< "FragTrap " << this->mName << " attacks " << target << ", causing " << this->mAttackDamage << " points of damage!"<< std::endl;
}