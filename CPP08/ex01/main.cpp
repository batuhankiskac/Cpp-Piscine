#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::cout << "--- Subject Test ---" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n--- Additional Test ---" << std::endl;
	try {
		Span sp2 = Span(15000);
		std::vector<int> largeVector;

		std::srand(time(NULL));
		for (int i = 0; i < 15000; ++i) {
			largeVector.push_back(std::rand() % 100000);
		}
		sp2.addNumber(largeVector.begin(), largeVector.end());
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Exception Test ---" << std::endl;
	try {
		Span sp3 = Span(3);
		sp3.addNumber(1);
		std::cout << sp3.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n--- Span Full Test ---" << std::endl;
	try {
		Span sp4 = Span(2);
		sp4.addNumber(1);
		sp4.addNumber(2);
		sp4.addNumber(3);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
