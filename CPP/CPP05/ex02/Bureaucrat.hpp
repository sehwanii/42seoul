#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string   mName;
    int                 mGrade;  //1~150 
public:
    Bureaucrat();
	Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName(void) const;
	int         getGrade(void) const;

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(Form &f);

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

std::ostream &operator<<(std::ostream &o, Bureaucrat &a);


#endif