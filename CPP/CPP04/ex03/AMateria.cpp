#include <iostream>
#include "AMateria.hpp"

/* ________________________ Orthodox Canonical Form _________________________ */
AMateria::AMateria() : type("none") {}

AMateria::AMateria(const AMateria& other) {
	this->type = other.type;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

AMateria::~AMateria() {}

/* __________________________ another Constructor ___________________________ */
AMateria::AMateria(std::string const & type) {
	this->type = type;
}

/* ____________________________ Getter & Setter _____________________________ */
std::string const & AMateria::getType() const {
	return (this->type);
}

/* _______________________________ Functions ________________________________ */
void AMateria::use(ICharacter& target) {
	if (type != "none")
		std::cout << "use " << this->type << "to " << target.getName() << std::endl;
}
