#include "Form.hpp"
#include <stdexcept>
#include <iostream>

// Default constructor
Form::Form()
    : m_name("Default"), m_isSigned(false), m_signGrade(150), m_execGrade(150) // m_grade를 멤버 초기화 리스트로 초기화
{
    std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
Form::Form(std::string name, int signGrade, int execGrade)
    : m_name(name), m_isSigned(false), m_signGrade(signGrade), m_execGrade(execGrade) // m_grade를 초기화 리스트로 초기화
{
    std::cout << "Form constructor called" << std::endl;
    if (signGrade < 1 || execGrade<1)
    {
        throw Form::GradeTooHighException();
    }
    else if (signGrade > 150|| execGrade > 150)
    {
        throw Form::GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form &other)
    : m_name(other.m_name), m_isSigned(other.m_isSigned), m_signGrade(other.m_signGrade), m_execGrade(other.m_execGrade) // 초기화 리스트 사용
{
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Form &Form::operator=(const Form &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // Self-assignment check
    {
        m_isSigned = other.m_isSigned;
    }
    return *this;
}

// Destructor
Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

// Getters
std::string Form::getName(void) const
{
    return m_name;
}

int Form::getSignGrade(void) const
{
    return m_signGrade;
}

int Form::getExecGrade(void) const
{
    return m_execGrade;
}

bool Form::getIsSigned(void) const
{
	return m_isSigned;
}

void Form::beSigned(Bureaucrat b){
	if(this->getSignGrade() < b.getGrade()){
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because";
		throw(Bureaucrat::GradeTooLowException());
	}
	else if(this->getIsSigned() == false){
		this->m_isSigned = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because Form is already signed" << std::endl;
	}
}

// Exception classes
const char *Form::GradeTooHighException::what(void) const throw()
{
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return "Form grade is too low!";
}

// Overloaded output operator
std::ostream &operator<<(std::ostream &o, Form &a)
{
    o << "Form " << a.getName() << ": sign grade: " << a.getSignGrade() << ": exec grade: " << a.getExecGrade()<< ": isSigned: " << a.getIsSigned() << std::endl;
    return (o);
}
