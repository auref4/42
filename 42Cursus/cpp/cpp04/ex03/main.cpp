#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << "42 main" << std::endl << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << "More test" << std::endl << std::endl;

		AMateria	*a = new Ice;
		AMateria	*b = new Ice;
		AMateria	*c = new Cure;
		AMateria	*d = new Cure;
		AMateria	*e = new Ice;

		Character	bob("bob");

		std::cout << std::endl;
		bob.equip(a);
		bob.equip(b);
		bob.equip(c);
		bob.equip(d);
		bob.equip(e);
		bob.unequip(2);
		bob.equip(e);
		std::cout << std::endl;

		delete c;
	}
	{
		std::cout << std::endl;

		AMateria	*a = new Ice;
		AMateria	*b = a->clone();

		Character	bob("bob");

		std::cout << std::endl;
		bob.equip(b);
		std::cout << std::endl;

		delete a;
	}
	{
		std::cout << std::endl;

		IMateriaSource* test = new MateriaSource();
		test->learnMateria(new Ice());
		AMateria* test2 = test->createMateria("cure");
		test->learnMateria(new Cure());
		test->learnMateria(new Cure());
		test->learnMateria(new Ice());
		AMateria* test3 = test->createMateria("cure");
		AMateria* test4 = test->createMateria("ice");
		(void) test3;
		(void) test4;
		delete test3;
		delete test4;
		std::cout << std::endl;

		ICharacter* bob = new Character("bob");
		ICharacter* steve = new Character("steve");

		std::cout << std::endl;

		bob->use(0, *steve);
		bob->use(1, *steve);
		bob->use(2, *steve);
		bob->use(3, *steve);
		bob->use(4, *steve);

		bob->unequip(2);
		bob->use(2, *steve);

		std::cout << std::endl;

		delete test;
		delete test2;
		delete bob;
		delete steve;
	}

	return 0;
}
