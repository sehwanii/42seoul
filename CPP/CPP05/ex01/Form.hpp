#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string   m_name;
    bool				m_isSigned;
	const int			m_signGrade;
	const int 			m_execGrade;
public:
    Form();
	Form(std::string name, int signGrade, int execGrade);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    std::string getName(void) const;
	int         getSignGrade(void) const;
	int         getExecGrade(void) const;
	bool		getIsSigned(void) const;

	void		beSigned(Bureaucrat b);


    class GradeTooHighException : public std::exception
	{
		public:
		  const char * what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		  const char * what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form &a);


#endif