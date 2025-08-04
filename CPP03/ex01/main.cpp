#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1: Basic ScavTrap functionality ---" << std::endl;
	{
		ScavTrap scav("SC4V-TP");
		scav.attack("a random target");
		scav.takeDamage(20);
		scav.beRepaired(10);
		std::cout << "--> Testing special ability..." << std::endl;
		scav.guardGate();
	}

	std::cout << "\n--- Test 2: ScavTrap with Zero Hit Points (Death) ---" << std::endl;
	{
		ScavTrap deadScav("Deady");
		deadScav.takeDamage(100);
		std::cout << "--> Trying to attack and use special ability with 0 HP..." << std::endl;
		deadScav.attack("another target");
		deadScav.guardGate();
	}

	std::cout << "\n--- Test 3: ScavTrap with Zero Energy Points (Exhaustion) ---" << std::endl;
	{
		ScavTrap tiredScav("Tired");
		std::cout << "--> Depleting all 50 energy points..." << std::endl;
		for (int i = 0; i < 50; ++i)
			tiredScav.attack("the same target over and over");

		std::cout << "--> Trying to repair and attack with 0 EP..." << std::endl;
		tiredScav.attack("one last time");
		tiredScav.beRepaired(20);
	}

	std::cout << "\n--- Test 4: Polymorphism (The most important test!) ---" << std::endl;
	{
		std::cout << "--> Creating a ScavTrap but storing it in a ClapTrap pointer..." << std::endl;
		ClapTrap* polyPtr = new ScavTrap("Poly");

		std::cout << "\n--> Calling attack() via the base class pointer..." << std::endl;
		std::cout << "    (Notice it calls ScavTrap's attack, thanks to 'virtual')" << std::endl;
		polyPtr->attack("the concept of polymorphism");

		std::cout << "\n--> Deleting via the base class pointer..." << std::endl;
		std::cout << "    (Notice both destructors are called, thanks to 'virtual destructor')" << std::endl;
		delete polyPtr;
	}

	std::cout << "\n--- End of main. Destructors for any remaining objects will be called. ---" << std::endl;

	return (0);
}
