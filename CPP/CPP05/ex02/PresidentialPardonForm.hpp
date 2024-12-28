#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string   m_name;
    bool				m_isSigned;
	const int			m_signGrade;
	const int 			m_execGrade;
	const std::string	m_target;
public:
    PresidentialPardonForm(std::string target);
	PresidentialPardonForm(std::string name, int signGrade, int execGrade);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
	void	execute(Bureaucrat const & executor) const;

};

#endif