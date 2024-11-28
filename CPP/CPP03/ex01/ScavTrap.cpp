/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 06:24:41 by sehwanii          #+#    #+#             */
/*   Updated: 2024/11/29 02:01:09 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	mName = "default";
	mHitPoint = 100;
	mEnergyPoint = 50;
	mAttackDamage = 20;
	std::cout << "ScavTrap " << mName << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	// this->mName = name;
	this->mHitPoint = 100;
	this->mEnergyPoint = 50;
	this->mAttackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->mName << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->mName = other.mName;
		this->mAttackDamage = other.mAttackDamage;
		this->mHitPoint = other.mHitPoint;
		this->mEnergyPoint = other.mEnergyPoint;
	}
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.mName)
{
	this->mAttackDamage = other.mAttackDamage;
	this->mEnergyPoint = other.mEnergyPoint;
	this->mHitPoint = other.mHitPoint;

	std::cout << "ScavTrap " << this->mName << " constructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (mEnergyPoint <= 0)
	{
		std::cout << "ScavTrap " << this->mName << " : No Energy..." << std::endl;
		return;
	}
	else if (mHitPoint <= 0)
	{
		std::cout <<"ScavTrap " << this->mName <<  " : No Hit Point..." << std::endl;
		return;
	}
	this->mEnergyPoint--;
	std::cout <<"ScavTrap "<< mName << " is now in Gatekeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (mEnergyPoint <= 0)
	{
		std::cout << "ScavTrap " << this->mName << " : No Energy..." << std::endl;
		return;
	}
	else if (mHitPoint <= 0)
	{
		std::cout << "ScavTrap " << this->mName << " : No Hit Point..." << std::endl;
		return;
	}
	this->mEnergyPoint--;
	std::cout << "ScavTrap " << this->mName << " attacks " << target << ", causing " << this->mAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (mHitPoint - amount < 0)
		mHitPoint = 0;
	else
		mHitPoint -= amount;
	std::cout << "ScavTrap " << mName << " has taken " << amount << " damage" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (mEnergyPoint <= 0)
	{
		std::cout << "ScavTrap " << this->mName << " : No Energy..." << std::endl;
		return;
	}
	else if (mHitPoint <= 0)
	{
		std::cout << "ScavTrap " << this->mName << " : No Hit Point..." << std::endl;
		return;
	}
	this->mEnergyPoint--;
	this->mHitPoint += amount;
	std::cout << "ScavTrap " << mName << " has been repaired " << amount << " Hit Point" << std::endl;
}