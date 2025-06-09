#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main( void ) {
	std::vector<int> vec;
	for (int i = 0; i < 7; i++)
		vec.push_back(i);

	try {
		std::cout << *easyfind(vec, 3) << "\n";
		std::cout << *(easyfind(vec, 3) + 1) << "\n";
		std::cout << *easyfind(vec, 7) << "\n";

		//int N = 3;
		//std::cout << *easyfind(3, 3) << "\n";
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
