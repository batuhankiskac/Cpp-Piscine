#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap clap("CL4P-TP");
	ScavTrap scav("SC4V-TP");
	FragTrap frag("FR4G-TP");

	std::cout << std::endl;

	clap.attack("a training dummy");
	scav.attack("a bigger training dummy");
	frag.attack("the biggest training dummy");

	std::cout << std::endl;

	scav.guardGate();
	frag.highFivesGuys();
	frag.takeDamage(90);

	std::cout << std::endl;

	ClapTrap* base_scav = new ScavTrap("PolyScav");
	ClapTrap* base_frag = new FragTrap("PolyFrag");

	std::cout << std::endl;

	base_scav->attack("the floor");
	base_frag->attack("the ceiling");

	std::cout << std::endl;

	delete base_scav;
	delete base_frag;

	std::cout << std::endl;

	FragTrap tiredFrag("TiredFrag");
	for (int i = 0; i < 101; i++)
		tiredFrag.beRepaired(1);
	tiredFrag.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
