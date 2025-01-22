#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());//zadt ice f tableau
	src->learnMateria(new Cure());// zadt cure f tableau
	ICharacter* me = new Character("me");

	AMateria	*ice = src->createMateria("ice");//j ai ceer un materiel ice et createMateria("ice") return ice qui existe dans le tableau
	me->equip(ice);//equipe le personnage me avec ice
	me->unequip(0);// desequipe
	delete ice;//free

	AMateria* tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(0, *bob);
	delete bob;
	delete me;
	delete src;

	return 0;
}

// int main() {
//     Character target("Player1");

//     Ice iceMateria;
//     Cure cureMateria;

//     AMateria* clonedIce = iceMateria.clone();
//     AMateria* clonedCure = cureMateria.clone();

//     clonedIce->use(target);
//     clonedCure->use(target);

//     delete clonedIce;
//     delete clonedCure;

//     return 0;
// }