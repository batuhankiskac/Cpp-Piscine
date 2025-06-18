#include "ClapTrap.hpp"

int main() {
	ClapTrap a("A");
	a.attack("B");
	a.beRepaired(5);

	ClapTrap c("C");
	c.takeDamage(10);
	c.attack("A");
	c.beRepaired(10);

	ClapTrap d("D");
	for (int i = 0; i < 11; ++i) {
		d.beRepaired(1);
	}
	d.attack("A");

	ClapTrap e("E");
	ClapTrap f(e);
	ClapTrap g("G");
	g = e;

	return (0);
}
