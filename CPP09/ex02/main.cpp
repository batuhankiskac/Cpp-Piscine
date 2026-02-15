#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error: No input provided." << std::endl;
		return 1;
	}

	PmergeMe pmm;
	pmm.execute(argc, argv);

	return 0;
}
