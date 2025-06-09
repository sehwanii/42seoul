#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main( void ) {
	std::cout << "\033[32;7m" << "1. MutantStack " << "\033[0m" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << "\033[30;2m" << "//top()" << "\033[0m" << std::endl;
	std::cout << mstack.top() << std::endl;
	
	std::cout << "\033[30;2m" << "//void pop()" << "\033[0m" << std::endl;
	mstack.pop();
	
	std::cout << "\033[30;2m" << "//size()" << "\033[0m" << std::endl;
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...] 
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "\033[30;2m" << "//while() {}" << "\033[0m" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);




	std::cout << "\033[32;7m" << "\n2. std::list " << "\033[0m" << std::endl;
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << "\033[30;2m" << "//back()" << "\033[0m" << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << "\033[30;2m" << "//void pop()" << "\033[0m" << std::endl;
	list.pop_back();
	std::cout << "\033[30;2m" << "//size()" << "\033[0m" << std::endl;
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...] 
	list.push_back(0);
	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();
	++it2;
	--it2;
	std::cout << "\033[30;2m" << "//while() {}" << "\033[0m" << std::endl;
	while (it2 != ite2) {
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;
}
