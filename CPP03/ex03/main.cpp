#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1: DiamondTrap Creation and Core Functionality ---" << std::endl;
	{
		std::cout << "--> Creating a DiamondTrap named 'Sparky'..." << std::endl;
		std::cout << "    (Notice the constructor chain: ClapTrap -> ScavTrap -> FragTrap -> DiamondTrap)" << std::endl;
		DiamondTrap sparky("Sparky");

		std::cout << "\n--> Testing the 'whoAmI()' function..." << std::endl;
		std::cout << "    (It should display both its own name and its ClapTrap name)" << std::endl;
		sparky.whoAmI();

		std::cout << "\n--> Testing inherited abilities..." << std::endl;
		std::cout << "    Attack (from ScavTrap): ";
		sparky.attack("a training dummy");
		std::cout << "    guardGate (from ScavTrap): ";
		sparky.guardGate();
		std::cout << "    highFivesGuys (from FragTrap): ";
		sparky.highFivesGuys();

		std::cout << "\n--> Testing inherited stats (HP from FragTrap, EP from ScavTrap)..." << std::endl;
		sparky.takeDamage(30);
		sparky.beRepaired(20);

		std::cout << "\n--> End of Test 1 scope. Destructor for 'sparky' will be called." << std::endl;
	}

	std::cout << "\n--- Test 2: Orthodox Canonical Form for DiamondTrap ---" << std::endl;
	{
		DiamondTrap sparky("Sparky");

		std::cout << "\n--> Testing Copy Constructor: DiamondTrap circuit(sparky);" << std::endl;
		DiamondTrap circuit(sparky);
		std::cout << "    'circuit' says: ";
		circuit.whoAmI();

		std::cout << "\n--> Testing Assignment Operator: bolt = sparky;" << std::endl;
		DiamondTrap bolt("Bolt");
		bolt = sparky;
		std::cout << "    'bolt' now says: ";
		bolt.whoAmI();
		bolt.attack("another training dummy");

		std::cout << "\n--> End of Test 2 scope. Destructors for 'sparky', 'circuit', and 'bolt' will be called." << std::endl;
	}

	std::cout << "\n--- End of main ---" << std::endl;
	return (0);
}
