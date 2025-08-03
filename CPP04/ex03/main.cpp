#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Subject's Mandatory Test ---" << std::endl;
	{
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

		std::cout << "> me uses slot 0 on bob:" << std::endl;
		me->use(0, *bob);
		std::cout << "> me uses slot 1 on bob:" << std::endl;
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << "\n//------------------------------------------------------------------//\n" << std::endl;


	std::cout << "--- Character Copy and Assignment (Deep Copy) Test ---" << std::endl;
	{
		Character* original = new Character("Original");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		original->equip(src->createMateria("ice"));

		Character* copy = new Character(*original);

		std::cout << "\n> 'Original' uses its first materia on 'Copy':" << std::endl;
		original->use(0, *copy);
		std::cout << "> 'Copy' uses its first materia on 'Original':" << std::endl;
		copy->use(0, *original);

		Character* assigned = new Character("Assigned");
		*assigned = *original;

		std::cout << "\n> 'Original' and 'Assigned' should now be identical." << std::endl;
		std::cout << "> 'Assigned' uses its first materia on 'Original':" << std::endl;
		assigned->use(0, *original);

		delete original;
		std::cout << "\n> 'Original' has been deleted. 'Copy' and 'Assigned' should still work." << std::endl;
		std::cout << "> 'Copy' uses its materia on 'Assigned':" << std::endl;
		copy->use(0, *assigned);


		delete copy;
		delete assigned;
		delete src;
	}
	std::cout << "\n//------------------------------------------------------------------//\n" << std::endl;


	std::cout << "--- Inventory and Edge Case Tests ---" << std::endl;
	{
		ICharacter* hero = new Character("Hero");
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

		hero->equip(src->createMateria("cure"));
		hero->equip(src->createMateria("ice"));
		hero->equip(src->createMateria("cure"));
		hero->equip(src->createMateria("ice"));

		AMateria* extra = src->createMateria("cure");
		hero->equip(extra);
		std::cout << "> Inventory is full. Address of 5th Materia: " << extra << " (not equipped)" << std::endl;
		delete extra;

		std::cout << "> Using invalid slot (-1):" << std::endl;
		hero->use(-1, *hero);
		std::cout << "> Using invalid slot (4):" << std::endl;
		hero->use(4, *hero);

		hero->unequip(1);
		std::cout << "> Unequipped materia from slot 1. Now using it (should do nothing):" << std::endl;
		hero->use(1, *hero);

		std::cout << "> Using slot 0:" << std::endl;
		hero->use(0, *hero);
		std::cout << "> Using slot 2:" << std::endl;
		hero->use(2, *hero);

		delete hero;
		delete src;
	}

	return 0;
}
