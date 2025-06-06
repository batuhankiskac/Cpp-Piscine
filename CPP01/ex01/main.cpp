#include "Zombie.hpp"

int main() {
	Zombie* horde;
	std::string name;
	int N;

	std::cout << "Enter the number of zombies: ";
	std::cin >> N;
	std::cout << "Enter the name for the zombies: ";
	std::cin >> name;

	horde = zombieHorde(N, name);
	if (horde == NULL) {
		std::cout << "Invalid number of zombies." << std::endl;
		return (1);
	}

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;

	return (0);
}
