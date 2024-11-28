#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat &other){
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
	{ // Self-assignment check
		// this->BureaucratValue = other.BureaucratValue;
	}
	return *this;
}
Bureaucrat::~Bureaucrat(){}

int Bureaucrat::GetGrade() const{
    return this->mGrade;
}

std::string Bureaucrat::GetName() const{
    return this->mName;
}

