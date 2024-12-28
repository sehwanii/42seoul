#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string   m_name;
    bool				m_isSigned;
	const int			m_signGrade;
	const int 			m_execGrade;
	const std::string	m_target;
public:
    RobotomyRequestForm(std::string target);
	RobotomyRequestForm(std::string name, int signGrade, int execGrade);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
	void	execute(Bureaucrat const & executor) const;
};

#endif