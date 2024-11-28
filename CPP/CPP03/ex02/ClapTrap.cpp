/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 05:11:15 by sehwanii          #+#    #+#             */
/*   Updated: 2024/11/29 02:31:22 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : mName("default"), mHitPoint(10), mEnergyPoint(10), mAttackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : mName(name), mHitPoint(10), mEnergyPoint(10), mAttackDamage(0)
{
	std::cout << "ClapTrap " << this->mName << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : mName(other.mName), mHitPoint(other.mHitPoint), mEnergyPoint(other.mEnergyPoint), mAttackDamage(other.mAttackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->mName = other.mName;
		this->mAttackDamage = other.mAttackDamage;
		this->mHitPoint = other.mHitPoint;
		this->mEnergyPoint = other.mEnergyPoint;
	}
	return *this;
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
		return;
	}
	else if (mHitPoint <= 0)
	{
		std::cout << "No Hit Point..." << std::endl;
		return;
	}
	this->mEnergyPoint--;
	std::cout << "ClapTrap " << this->mName << " attacks " << target << ", causing " << this->mAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	mHitPoint -= amount;
	std::cout << "ClapTrap " << mName << " has taken " << amount << " damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (mEnergyPoint <= 0)
	{
		std::cout << "No Energy..." << std::endl;
		return;
	}
	else if (mHitPoint <= 0)
	{
		std::cout << "No Hit Point..." << std::endl;
		return;
	}
	this->mEnergyPoint--;
	this->mHitPoint += amount;
	std::cout << "ClapTrap " << mName << " has been repaired " << amount << " Hit Point" << std::endl;
}