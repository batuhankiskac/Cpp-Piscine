#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	{
		ScavTrap scav("SC4V-TP");
		scav.attack("a random target");
		scav.takeDamage(20);
		scav.beRepaired(10);
		scav.guardGate();
	}

	std::cout << std::endl;

	ScavTrap deadScav("Deady");
	deadScav.takeDamage(100);
	deadScav.attack("another target");
	deadScav.guardGate();

	std::cout << std::endl;

	ScavTrap tiredScav("Tired");
	for (int i = 0; i < 51; ++i)
		tiredScav.attack("the same target over and over");
	tiredScav.beRepaired(20);

	std::cout << std::endl;

	ClapTrap* polyPtr = new ScavTrap("Poly");
	polyPtr->attack("the concept of polymorphism");
	delete polyPtr;

	return (0);
}
