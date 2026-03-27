#include "easyfind.hpp"

int main() {
	std::vector<int> x;

	for (int i = 0; i < 10; ++i)
		x.push_back(i);

	std::vector<int>::iterator it = easyfind(x, 4);
	if (it != x.end())
		std::cout << "Value found!\n";

	easyfind(x, 14);

	return 0;
}
