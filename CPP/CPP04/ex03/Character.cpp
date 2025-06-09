#include <iostream>
#include "Character.hpp"

/* ________________________ Orthodox Canonical Form _________________________ */
Character::Character() : name("default") {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.name) {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
 	for (int i = 0; i < 4; i++)
		if (other.inventory[i] != NULL)
			this->inventory[i] = other.inventory[i]->clone();
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < 4; i++)
			if (this->inventory[i] != NULL)
				delete this->inventory[i];
		for (int i = 0; i < 4; i++)
			if (other.inventory[i] != NULL)
				this->inventory[i] = other.inventory[i]->clone();
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
}

/* __________________________ another Constructor ___________________________ */
Character::Character(std::string const & name) : name(name) {
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

/* ____________________________ Getter & Setter _____________________________ */
std::string const & Character::getName() const {
	return (this->name);
}

/* __________________________ Interface Overriding __________________________ */
void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			return ;
		}
	}
	std::cerr << "Error: Character " << this->getName() << "'s inventory is full." << std::endl;
}

//please, Store materia[idx] before call unequip()
void Character::unequip(int idx) {
	if (0 <= idx && idx < 4) {
		if (this->inventory[idx] == NULL)
			std::cout << "Character " << this->getName() << "'s inventory[" << idx << "] is unexisting." << std::endl;
		else
			this->inventory[idx] = NULL;
	}
	else
		std::cerr << "Error: invalid inventory index" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (0 <= idx && idx < 4) {
		if (this->inventory[idx] == NULL)
			std::cout << "Character " << this->getName() << "'s inventory[" << idx << "] is unexisting." << std::endl;
		else
			this->inventory[idx]->use(target);
	}
	else
		std::cerr << "Error: invalid inventory index" << std::endl;
}
