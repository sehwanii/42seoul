#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp1;
	tmp1 = src->createMateria("ice");
	me->equip(tmp1);
	AMateria* tmp2;
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\033[37;2m" << std::endl << "// use & enquip, invalid index" << "\033[0m" << std::endl;
	me->use(2, *bob);
	me->use(6, *bob);

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(6);

	std::cout << "\033[37;2m" << std::endl << "// full MateriaSource" << "\033[0m" << std::endl;

	AMateria* tmp3;
	tmp3 = new Cure();
	src->learnMateria(tmp3);
	tmp3 = new Cure();
	src->learnMateria(tmp3);
	tmp3 = new Cure();
	src->learnMateria(tmp3);
	
	std::cout << "\033[37;2m" << std::endl << "// none type" << "\033[0m" << std::endl;
	if (src->createMateria("none") == NULL)
		std::cout << "(none type)" << std::endl;

	/*
	std::cout << "\033[37;2m" << "// Character's deep copy in DEBUG mode " << "\033[0m" << std::endl;
	Character one("one");
	Character two("two");
	*/

	delete bob;
	delete me;
	delete src;
	delete tmp1;
	delete tmp2;
	delete tmp3;

	return 0;
}
