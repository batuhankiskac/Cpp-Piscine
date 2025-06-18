#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	DiamondTrap sparky("Sparky");

	std::cout << std::endl;

	sparky.whoAmI();
	sparky.attack("a training dummy");
	sparky.takeDamage(30);
	sparky.beRepaired(20);
	sparky.guardGate();
	sparky.highFivesGuys();

	std::cout << std::endl;

	DiamondTrap bolt("Bolt");
	bolt = sparky;

	std::cout << std::endl;

	bolt.whoAmI();
	bolt.attack("another training dummy");

	std::cout << std::endl;

	DiamondTrap circuit(sparky);
	circuit.whoAmI();

	std::cout << std::endl;

	return (0);
}
