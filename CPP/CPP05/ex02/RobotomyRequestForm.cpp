#include "RobotomyRequestForm.hpp"
#include <stdexcept>
#include <iostream>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : m_name(target + "_Robotomy"), m_isSigned(false), m_signGrade(72), m_execGrade(45), m_target(target) // m_grade를 멤버 초기화 리스트로 초기화
{
    std::cout << "Robotomy constructor called" << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : m_name(other.m_name), m_isSigned(other.m_isSigned), m_signGrade(other.m_signGrade), m_execGrade(other.m_execGrade), m_target(other.m_target) // 초기화 리스트 사용
{
    std::cout << "Robotomy Copy constructor called" << std::endl;
}

// Assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "Robotomy Copy assignment operator called" << std::endl;
    if (this != &other) // Self-assignment check
    {
        m_isSigned = other.m_isSigned;
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
	std::time_t currentTime = std::time(nullptr);
	if (currentTime % 2 == 0)
    	std::cout << this->m_target << " has been robotomized successful." << std::endl;
    else
		std::cout << this->m_target << " has failed to robotomize." << std::endl;
}