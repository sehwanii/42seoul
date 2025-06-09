#include <iostream>
#include "Span.hpp"

int main( void ) {
	std::cout << "\033[32;7m" << "1. Subject main() " << "\033[0m" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "\033[30;2m" << "// shortest & longest" << "\033[0m" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << "\033[32;7m" << "\n2. Add more " << "\033[0m" << std::endl;
	try {
		sp.addNumber(11);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	std::cout << "\033[32;7m" << "\n3. Fill Randomly " << "\033[0m" << std::endl;
	Span sp2 = Span(10);
	sp2.fillAll();
	sp2.printAll();

	std::cout << "\033[30;2m" << "// shortest & longest" << "\033[0m" << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;



	std::cout << "\033[32;7m" << "\n4. Big Size " << "\033[0m" << std::endl;
	Span sp3 = Span(10000);
	sp3.fillAll();
	//sp3.printAll();

	std::cout << "\033[30;2m" << "// shortest & longest" << "\033[0m" << std::endl;
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return 0;
}
