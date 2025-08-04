#include "ClapTrap.hpp"
#include <iostream>

int main() {
	std::cout << "--- Test 1: Basic functionality (Creation, Attack, Repair) ---" << std::endl;
	{
		ClapTrap a("A");
		a.attack("B");
		a.beRepaired(5);
	}
	std::cout << "\n--- Test 2: Zero Hit Points (Death) ---" << std::endl;
	{
		ClapTrap c("C");
		c.takeDamage(10);
		std::cout << "--> Trying to attack and repair with 0 HP..." << std::endl;
		c.attack("A");
		c.beRepaired(10);
	}
	std::cout << "\n--- Test 3: Zero Energy Points (Exhaustion) ---" << std::endl;
	{
		ClapTrap d("D");
		std::cout << "--> Depleting all energy points..." << std::endl;
		for (int i = 0; i < 10; ++i)
			d.beRepaired(1);
		std::cout << "--> Trying to attack and repair with 0 EP..." << std::endl;
		d.attack("A");
		d.beRepaired(1);
	}
	std::cout << "\n--- Test 4: Orthodox Canonical Form (Copy and Assignment) ---" << std::endl;
	{
		std::cout << "--> Creating original object 'e'..." << std::endl;
		ClapTrap e("E");

		std::cout << "\n--> Testing Copy Constructor: ClapTrap f(e);" << std::endl;
		ClapTrap f(e);

		std::cout << "\n--> Testing Assignment Operator: g = e;" << std::endl;
		ClapTrap g("G");
		g = e;

		std::cout << "\n--> End of OCF test scope. Destructors will be called." << std::endl;
	}
	std::cout << "\n--- End of main. Destructors for remaining objects will be called. ---" << std::endl;

	return (0);
}
