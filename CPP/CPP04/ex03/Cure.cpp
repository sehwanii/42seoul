#include <iostream>
#include "Cure.hpp"

/* ________________________ Orthodox Canonical Form _________________________ */
Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {
	this->type = other.type;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Cure::~Cure() {}

/* _______________________________ Functions ________________________________ */
Cure* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
