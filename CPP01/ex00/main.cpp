#include "Zombie.hpp"

int main() {
	Zombie* zombie1 = newZombie("Zombie1");
	Zombie* zombie2 = newZombie("Zombie2");

	zombie1->announce();
	zombie2->announce();

	delete zombie1;
	delete zombie2;

	randomChump("RandomZombie");

	return (0);
}

