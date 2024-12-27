#include "whatever.hpp"
#include <iostream>
#include <string>

int main(){
	{
		int a = 2;
		int b = 3;
		std::cout << "before swap - a : "<<a<<" b : "<<b<<std::endl;
		swap(a,b);
		std::cout << "after swap  - a : "<<a<<" b : "<<b<<std::endl;

		std::cout << "max : "<<::max(a, b)<<std::endl;
		std::cout << "min : "<<::min(a, b)<<std::endl;
	}

	std::cout << std::endl << "------------------------------------------------------------------" << std::endl << std::endl;
	
	{
		float a = 2.1234;
		float b = 2.3456;
		std::cout << "before swap - a : "<<a<<" b : "<<b<<std::endl;
		swap(a,b);
		std::cout << "after swap  - a : "<<a<<" b : "<<b<<std::endl;

		std::cout << "max : "<<::max(a, b)<<std::endl;
		std::cout << "min : "<<::min(a, b)<<std::endl;
	}

	std::cout << std::endl << "------------------------------------------------------------------" << std::endl << std::endl;

	{
		std::string a = "Hello";
		std::string b = "World!";
		std::cout << "before swap - a : "<<a<<" b : "<<b<<std::endl;
		swap(a,b);
		std::cout << "after swap  - a : "<<a<<" b : "<<b<<std::endl;

		std::cout << "max : "<<::max(a, b)<<std::endl;
		std::cout << "min : "<<::min(a, b)<<std::endl;
	}
}

// int main(void)
// {
// 	int a = 2;
// 	int b = 3;
// 	::swap(a, b);
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
// 	return 0;
// }