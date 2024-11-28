/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 06:24:41 by sehwanii          #+#    #+#             */
/*   Updated: 2024/11/29 02:31:28 by sehwjang         ###   ########.fr       */
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

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout<< "FragTrap "<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
	{
		this->mName = other.mName;
		this->mAttackDamage = other.mAttackDamage;
    	this->mHitPoint = other.mHitPoint;
    	this->mEnergyPoint = other.mEnergyPoint;
	}
	return *this;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.mName)
{
    this->mAttackDamage = other.mAttackDamage;
    this->mEnergyPoint = other.mEnergyPoint;
    this->mHitPoint = other.mHitPoint;

    std::cout << "FragTrap " << this->mName << " constructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (mEnergyPoint <= 0)
    {
        std::cout << "FragTrap " << this->mName<< " : No Energy..." << std::endl;
        return ;
    }
    else if (mHitPoint <= 0)
    {
        std::cout << "FragTrap " << this->mName<< " : No Hit Point..." << std::endl;
        return ;
    }
	this->mEnergyPoint--;
    std::cout<<"FragTrap " << mName<<" high fives with guys~"<<std::endl;
}

void FragTrap::attack(const std::string &target)
{
    if (mEnergyPoint <= 0)
    {
        std::cout << "FragTrap " << this->mName<< " : No Energy..." << std::endl;
        return ;
    }
    else if (mHitPoint <= 0)
    {
        std::cout << "FragTrap " << this->mName<< " : No Hit Point..." << std::endl;
        return ;
    }
    std::cout	<< "FragTrap " << this->mName << " attacks " << target << ", causing " << this->mAttackDamage << " points of damage!"<< std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	mHitPoint -= amount;
	std::cout << "FragTrap " << mName << " has taken " << amount << " damage" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (mEnergyPoint <= 0)
	{
		std::cout << "FragTrap " << this->mName << " : No Energy..." << std::endl;
		return;
	}
	else if (mHitPoint <= 0)
	{
		std::cout << "FragTrap " << this->mName << " : No Hit Point..." << std::endl;
		return;
	}
	this->mEnergyPoint--;
	this->mHitPoint += amount;
	std::cout << "FragTrap " << mName << " has been repaired " << amount << " Hit Point" << std::endl;
}