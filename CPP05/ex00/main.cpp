#include "Bureaucrat.hpp"
#include <iostream>

void printTitle(std::string title)
{
	std::cout << "\n" << "\033[1;36m" << "--- " << title << " ---" << "\033[0m" << std::endl;
}

int main() {

	printTitle("Test 1: Create Bureaucrat with valid grade");
	try {
		Bureaucrat b1("Ali", 75);
		std::cout << b1 << std::endl;

		Bureaucrat b2("Mehmet", 1);
		std::cout << b2 << std::endl;

		Bureaucrat b3("Ayse", 150);
		std::cout << b3 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 2: Create Bureaucrat with invalid high grade");
	try {
		Bureaucrat b4("InvalidHigh", 0);
		std::cout << b4 << std::endl;

	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 3: Create Bureaucrat with invalid low grade");
	try {
		Bureaucrat b5("InvalidLow", 151);
		std::cout << b5 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 4: Increment+");
	try {
		Bureaucrat b6("Batuhan", 1);
		std::cout << b6 << std::endl;

		b6.incrementGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 5: Decrement-");
	try {
		Bureaucrat b7("Zeynep", 150);
		std::cout << b7 << std::endl;

		b7.decrementGrade();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
