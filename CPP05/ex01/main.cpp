#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void printTitle(std::string title)
{
	std::cout << "\n" << "\033[1;36m" << "--- " << title << " ---" << "\033[0m" << std::endl;
}

int main() {

	printTitle("Test 1: Valid Form Creation");
	try {
		Form f1("FormA", 50, 100);
		std::cout << f1 << std::endl;

		Form f2("FormB", 1, 1);
		std::cout << f2 << std::endl;

		Form f3("FormC", 150, 150);
		std::cout << f3 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 2: Invalid Form Creation with invalid high grade");
	try {
		Form f4("InvalidHigh", 0, 100);
		std::cout << f4 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 3: Invalid Form Creation with invalid low grade");
	try {
		Form f5("InvalidLow", 151, 100);
		std::cout << f5 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 4: Bureaucrat signing forms (Successful)");
	try {
		Bureaucrat b1("Alice", 30);
		Form f6("FormD", 50, 100);
		std::cout << b1 << std::endl;
		std::cout << f6 << std::endl;

		b1.signForm(f6);
		std::cout << f6 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 5: Bureaucrat signing forms (Failure(Grade Too Low))");
	try {
		Bureaucrat b2("Bob", 100);
		Form f7("FormE", 50, 100);
		std::cout << b2 << std::endl;
		std::cout << f7 << std::endl;

		b2.signForm(f7);
		std::cout << f7 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Test 6: Bureaucrat signing forms (Exact Grade)");
	try {
		Bureaucrat b3("Charlie", 50);
		Form f8("FormF", 50, 100);
		std::cout << b3 << std::endl;
		std::cout << f8 << std::endl;

		b3.signForm(f8);
		std::cout << f8 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
