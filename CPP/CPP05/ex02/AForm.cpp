#include "AForm.hpp"
#include <stdexcept>
#include <iostream>

// Default constructor
AForm::AForm()
    : m_name("Default"), m_isSigned(false), m_signGrade(150), m_execGrade(150) // m_grade를 멤버 초기화 리스트로 초기화
{
    std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
AForm::AForm(std::string name, int signGrade, int execGrade)
    : m_name(name), m_isSigned(false), m_signGrade(signGrade), m_execGrade(execGrade) // m_grade를 초기화 리스트로 초기화
{
    std::cout << "AForm constructor called" << std::endl;
    if (signGrade < 1 || execGrade<1)
    {
        throw AForm::GradeTooHighException();
    }
    else if (signGrade > 150|| execGrade > 150)
    {
        throw AForm::GradeTooLowException();
    }
}

// Copy constructor
AForm::AForm(const AForm &other)
    : m_name(other.m_name), m_isSigned(other.m_isSigned), m_signGrade(other.m_signGrade), m_execGrade(other.m_execGrade) // 초기화 리스트 사용
{
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // Self-assignment check
    {
        m_isSigned = other.m_isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}

// Getters
std::string AForm::getName(void) const
{
    return m_name;
}

int AForm::getSignGrade(void) const
{
    return m_signGrade;
}

int AForm::getExecGrade(void) const
{
    return m_execGrade;
}

bool AForm::getIsSigned(void) const
{
	return m_isSigned;
}

void AForm::beSigned(Bureaucrat b){
	if(this->getSignGrade() < b.getGrade()){
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because";
		throw(Bureaucrat::GradeTooLowException());
	}
	else if(this->getIsSigned() == false){
		this->m_isSigned = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because AForm is already signed" << std::endl;
	}
}

void AForm::checkExecutable(Bureaucrat b) const{
	if(this->m_isSigned == false){
		std::cout << b.getName() << " couldn't execute " << this->getName() << " because";
		throw FormNotSignedException();
	}
	else if(this->getExecGrade() > b.getGrade()){
		std::cout << b.getName() << " couldn't execute " << this->getName() << " because";
		throw Bureaucrat::GradeTooLowException();
	}
}

// Exception classes
const char *AForm::GradeTooHighException::what(void) const throw()
{
    return "Form grade is too high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return "Form grade is too low!";
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return "Form is not signed!";
}
// Overloaded output operator
std::ostream &operator<<(std::ostream &o, AForm &a)
{
    o << "AForm " << a.getName() << ": sign grade: " << a.getSignGrade() << ": exec grade: " << a.getExecGrade()<< ": isSigned: " << a.getIsSigned() << std::endl;
    return (o);
}
