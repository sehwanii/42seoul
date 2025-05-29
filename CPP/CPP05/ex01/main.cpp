#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define C_TITLE "\033[32;7m"
#define C_TITLEN "\033[32;7m\n"
#define C_RESET "\033[0m"

int main( void ) {
	std::cout << C_TITLE "< 1. Invalid Form >" C_RESET << std::endl;
	try {
		Form form3("form3", 151, 0);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << C_TITLEN "< 2. Successful Sign >" C_RESET << std::endl;
	try {
		Bureaucrat b1("One", 5);
		Form form1("Form1", 10, 10);

		std::cout << form1;
		b1.signForm(form1);
		std::cout << form1;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << C_TITLEN "< 3. Failed Sign >" C_RESET << std::endl;
	try {
		Bureaucrat b2("Two", 5);
		Form form2("Form2", 2, 7);

		std::cout << form2;
		b2.signForm(form2);
		std::cout << form2;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
