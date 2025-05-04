/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:04:59 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 17:05:00 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdexcept>
#include <iostream>
#include <ctime>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target + "_Robotomy", 72, 45), m_target(target) // m_grade를 멤버 초기화 리스트로 초기화
{
    std::cout << "Robotomy constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    :  AForm(other), m_target(other.m_target) // 초기화 리스트 사용
{
    std::cout << "Robotomy Copy constructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "Robotomy Copy assignment operator called" << std::endl;
    if (this != &other) // Self-assignment check
    {
        AForm::operator=(other);        
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy Destructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	checkExecutable(executor);
	std::cout << "Drilling....." << std::endl;
	std::time_t currentTime = std::time(0);
	if (currentTime % 2 == 0)
    	std::cout << this->m_target << " has been robotomized successful." << std::endl;
    else
		std::cout << this->m_target << " has failed to robotomize." << std::endl;
}