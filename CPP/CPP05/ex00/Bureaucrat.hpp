#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
    const std::string   mName;
    int                 mGrade;  //1~150 
public:
    Bureaucrat(/* args */);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string GetName(void) const;
	int         GetGrade(void) const;

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

Bureaucrat::Bureaucrat(/* args */)
{
}

Bureaucrat::~Bureaucrat()
{
}


#endif