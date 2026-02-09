#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, const char *argv[]) {
	if (argc != 2) {
		std::cerr << "Error: Could not open file." << std::endl;
		return -1;
	}

	try {
		BitcoinExchange btc;
		btc.execute(argv[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return -1;
	}
	return 0;
}
