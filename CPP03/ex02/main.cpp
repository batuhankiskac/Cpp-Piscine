#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1: Creating all three robot types ---" << std::endl;
	{
		ClapTrap clap("CL4P-TP");
		ScavTrap scav("SC4V-TP");
		FragTrap frag("FR4G-TP");

		std::cout << "\n--> Testing individual attack overrides..." << std::endl;
		clap.attack("a training dummy");
		scav.attack("a bigger training dummy");
		frag.attack("the biggest training dummy");

		std::cout << "\n--> Testing special abilities..." << std::endl;
		scav.guardGate();
		frag.highFivesGuys();

		std::cout << "\n--> Testing FragTrap's unique stats..." << std::endl;
		frag.takeDamage(90);
	}

	std::cout << "\n--- Test 2: Polymorphism with ScavTrap and FragTrap ---" << std::endl;
	{
		std::cout << "--> Creating derived classes and storing them in base class pointers..." << std::endl;
		ClapTrap* base_scav = new ScavTrap("PolyScav");
		ClapTrap* base_frag = new FragTrap("PolyFrag");

		std::cout << "\n--> Calling virtual attack() via base pointers..." << std::endl;
		std::cout << "    (Notice each pointer calls the correct derived attack function)" << std::endl;
		base_scav->attack("the floor");
		base_frag->attack("the ceiling");

		std::cout << "\n--> Deleting via base pointers..." << std::endl;
		std::cout << "    (Virtual destructors ensure correct cleanup for both types)" << std::endl;
		delete base_scav;
		delete base_frag;
	}

	std::cout << "\n--- Test 3: FragTrap with Zero Energy Points (Exhaustion) ---" << std::endl;
	{
		FragTrap tiredFrag("TiredFrag");
		std::cout << "--> Depleting all 100 energy points of FragTrap..." << std::endl;
		for (int i = 0; i < 100; i++)
			tiredFrag.beRepaired(1);

		std::cout << "--> Trying to use abilities with 0 EP..." << std::endl;
		tiredFrag.beRepaired(1);
		tiredFrag.highFivesGuys();
	}

	std::cout << "\n--- End of main ---" << std::endl;

	return (0);
}
