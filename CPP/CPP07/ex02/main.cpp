#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> a(3);
        a[0] = 10;
        a[1] = 20;
        a[2] = 30;

        Array<int> b = a;  // copy constructor
        b[1] = 99;

        Array<int> c;
        c = a;             // assignment operator
        c[2] = 77;

        std::cout << "Array a: ";
        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        std::cout << "Array b: ";
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "Array c: ";
        for (unsigned int i = 0; i < c.size(); ++i)
            std::cout << c[i] << " ";
        std::cout << std::endl;

        std::cout << "Try invalid access: " << std::endl;
        std::cout << a[10] << std::endl;  // will throw

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
