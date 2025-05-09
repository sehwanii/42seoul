/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:04:18 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 17:04:20 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

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