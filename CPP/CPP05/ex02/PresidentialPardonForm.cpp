#include "PresidentialPardonForm.hpp"
#include <stdexcept>
#include <iostream>

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : m_name(target + "_Presidential"), m_isSigned(false), m_signGrade(25), m_execGrade(5), m_target(target) // m_grade를 멤버 초기화 리스트로 초기화
{
    std::cout << "Presidential constructor called" << std::endl;
	std::cout << target<<" has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : m_name(other.m_name), m_isSigned(other.m_isSigned), m_signGrade(other.m_signGrade), m_execGrade(other.m_execGrade), m_target(other.m_target) // 초기화 리스트 사용
{
    std::cout << "Presidential Copy constructor called" << std::endl;
}

// Assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "Presidential Copy assignment operator called" << std::endl;
    if (this != &other) // Self-assignment check
    {
        m_isSigned = other.m_isSigned;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	this->checkExecutable(executor);
	std::cout<<m_target<< " has been pardoned by Zaphod Beeblebrox"<<std::endl;
}