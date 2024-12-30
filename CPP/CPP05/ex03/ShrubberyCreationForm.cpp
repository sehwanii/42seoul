/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:06:50 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 17:06:51 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : m_name("Shrubbery"), m_isSigned(false), m_signGrade(145), m_execGrade(137), m_target(target) // m_grade를 멤버 초기화 리스트로 초기화
{
    std::cout << "Shrubbery constructor called" << std::endl;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : m_name(other.m_name), m_isSigned(other.m_isSigned), m_signGrade(other.m_signGrade), m_execGrade(other.m_execGrade), m_target(other.m_target) // 초기화 리스트 사용
{
    std::cout << "Shrubbery Copy constructor called" << std::endl;
}

// Assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "Shrubbery Copy assignment operator called" << std::endl;
    if (this != &other) // Self-assignment check
    {
        m_isSigned = other.m_isSigned;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery Destructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	checkExecutable(executor);
	std::ofstream out(m_target + "_shrubbery");
	std::cout<<m_target + "_shrubbery file has been created"<<std::endl;
}