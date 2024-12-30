/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:05:37 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 17:05:39 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat()
    : mName("Default"), mGrade(150) // Default constructor
{
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : mName(name) // Constructor
{
    std::cout << "Bureaucrat constructor called" << std::endl;
	this->mGrade = grade;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : mName(other.mName), mGrade(other.mGrade) // Copy constructor
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) // Self-assignment check
    {
        mGrade = other.mGrade; // Only mGrade is assigned because mName is const
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
    return mName;
}

int Bureaucrat::getGrade(void) const
{
    return mGrade;
}

void Bureaucrat::incrementGrade()
{
    if (mGrade <= 1) // 1보다 높은 등급은 허용되지 않음
        throw GradeTooHighException();
    mGrade--; // 등급 증가 (숫자 감소)
}

void Bureaucrat::decrementGrade()
{
    if (mGrade >= 150) // 150보다 낮은 등급은 허용되지 않음
        throw GradeTooLowException();
    mGrade++; // 등급 감소 (숫자 증가)
}

void	Bureaucrat::signForm(AForm &f){
	f.beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Grade is too low!";
}

void	Bureaucrat::executeForm(AForm const & form){
	try {
    	form.execute(*this);
    	std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
    	std::cout << this->getName() << " couldn't execute " <<
    	form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o << "Bureaucrat " << a.getName() << ": grade: " << a.getGrade() << std::endl;
	return (o);
}
