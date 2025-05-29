#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define C_TITLE "\033[32;7m"
#define C_TITLEN "\033[32;7m\n"
#define C_COMMENT "\033[30;7m\n"
#define C_RESET "\033[0m"

int main( void ) {
	Bureaucrat				S1("sign1", 1);
	Bureaucrat				B5("bur1", 5);
	Bureaucrat				B70("bur2", 70);
	Bureaucrat				B150("bur2", 150);
	ShrubberyCreationForm	F1("target1");
	RobotomyRequestForm		F2("target1");
	PresidentialPardonForm	F3("target1");

	std::cout << C_TITLE "< 1. print Concrete Form info >" C_RESET << std::endl;
	std::cout << F1;
	std::cout << F2;
	std::cout << F3;

	std::cout << C_TITLEN "< 2. Failed Execute >" C_RESET << std::endl;
	try {
		F1.execute(B150);
		F2.execute(B150);
		F3.execute(B150);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << C_COMMENT "// sign to form" C_RESET << std::endl;
	try {
		B70.signForm(F1);
		B70.signForm(F2);
		B70.signForm(F3);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		S1.signForm(F1);
		S1.signForm(F2);
		S1.signForm(F3);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << C_TITLEN "< 3. Successful Execute >" C_RESET << std::endl;
	try {
		F1.execute(B5);    std::cout << std::endl;
		F2.execute(B5);    std::cout << std::endl;
		F3.execute(B5);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
