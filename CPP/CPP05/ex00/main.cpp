/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:04:03 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 17:04:14 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		try
		{
			Bureaucrat test("test", 200);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		Bureaucrat a("a", 150);
		Bureaucrat b("b", 1);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
		
		a.decrementGrade();
	
		b.incrementGrade();
	
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;

		// a.incrementGrade();
		// b.decrementGrade();
		// std::cout << a << std::endl;
		// std::cout << b << std::endl;
		// std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}