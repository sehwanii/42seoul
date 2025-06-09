#include <iostream>
#include "MateriaSource.hpp"

/* ________________________ Orthodox Canonical Form _________________________ */
MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		this->store[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++)
		if (this->store[i] != NULL)
			delete this->store[i];
 	for (int i = 0; i < 4; i++)
		if (other.store[i] != NULL)
			this->store[i] = other.store[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++)
			if (this->store[i] != NULL)
				delete this->store[i];
		for (int i = 0; i < 4; i++)
			if (other.store[i] != NULL)
				this->store[i] = other.store[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		if (this->store[i] != NULL)
			delete this->store[i];
}

/* __________________________ Interface Overriding __________________________ */
void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->store[i] == NULL) {
			this->store[i] = m;
			return ;
		}
	}
	std::cerr << "Error: This MateriaSource is full." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 3; i >= 0; i--) {
		if (this->store[i] != NULL \
		&& this->store[i]->getType() == type)
			return this->store[i]->clone();
	}
	return 0;
}
