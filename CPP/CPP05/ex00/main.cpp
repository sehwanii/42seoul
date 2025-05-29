#include <iostream>
#include "Bureaucrat.hpp"

#define C_TITLE "\033[32;7m"
#define C_TITLEN "\033[32;7m\n"
#define C_RESET "\033[0m"

int main( void ) {
	std::cout << C_TITLE "< 0. Insertion operator >" C_RESET << std::endl;
	Bureaucrat b1("test", 10);
	std::cout << b1 << std::endl;

	std::cout << C_TITLE "< 1. Constructor >" C_RESET << std::endl;
	try {
		Bureaucrat b1("one", 0);    std::cout << "one) OK" << std::endl;
		Bureaucrat b2("two", 151);  std::cout << "two) OK" << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << C_TITLEN "< 2. Increment >" C_RESET << std::endl;
	try {
		Bureaucrat b3("three", 3);

		b3.incrementGrade();        std::cout << "1) OK" << std::endl;
		b3.incrementGrade();        std::cout << "2) OK" << std::endl;
		b3.incrementGrade();        std::cout << "3) OK" << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << C_TITLEN "< 3. Decrement >" C_RESET << std::endl;
	try {
		Bureaucrat b4("four", 149);

		b4.decrementGrade();        std::cout << "1) OK" << std::endl;
		b4.decrementGrade();        std::cout << "2) OK" << std::endl;
		b4.decrementGrade();        std::cout << "3) OK" << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
