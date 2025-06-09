#include <iostream>
#include "Ice.hpp"

/* ________________________ Orthodox Canonical Form _________________________ */
Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {
	this->type = other.type;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Ice::~Ice() {}

/* _______________________________ Functions ________________________________ */
Ice* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
