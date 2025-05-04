/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:42:31 by sehwjang          #+#    #+#             */
/*   Updated: 2024/12/30 18:42:32 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
// Destructor
Base::~Base()
{
}

Base* generate() {
	int random;

	srand(time(0));
	random = rand();
	if (random % 3 == 0)
		return new A();
	else if (random % 3 == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	std::cout << "Actual type (*): ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base& p) {
	std::cout << "Actual type (&): ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (...) {}
}