/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:07:20 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 17:07:21 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string   m_name;
    bool				m_isSigned;
	const int			m_signGrade;
	const int 			m_execGrade;
	const std::string	m_target;	
public:
    ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(std::string name, int signGrade, int execGrade);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
	void	execute(Bureaucrat const & executor) const;
};

#endif