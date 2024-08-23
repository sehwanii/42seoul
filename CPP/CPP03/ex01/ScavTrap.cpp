/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwanii <sehwanii@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-12 06:24:41 by sehwanii          #+#    #+#             */
/*   Updated: 2024-08-12 06:24:41 by sehwanii         ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    mName = "default";    
    mHitPoint = 100;
    mEnergyPoint = 50;
    mAttackDamage = 20;
    std::cout << "ScavTrap " << mName << " constructor called" << std::endl;
}


ScavTrap::ScavTrap(std::string name){
    this->mName = name;
    this->mHitPoint = 100;
    this->mEnergyPoint = 50;
    this->mAttackDamage = 20;
    std::cout << "ScavTrap "<<name<<" constructor called"<<std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap "<<this->mName<<" destructor called"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
    this->mName = other.mName;
    this->mAttackDamage = other.mAttackDamage;
    this->mEnergyPoint = other.mEnergyPoint;
    this->mHitPoint = other.mHitPoint;

    std::cout << "ScavTrap " << this->mName << " constructor called" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout<<mName<<" is now in Gatekeeper mode"<<std::endl;
}

void ScavTrap::attack(const std::string &target)
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
    std::cout	<< "ScavTrap " << this->mName << " attacks " << target << ", causing " << this->mAttackDamage << " points of damage!"<< std::endl;
}