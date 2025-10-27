#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void printTitle(std::string title)
{
	std::cout << "\n" << "\033[1;36m" << "--- " << title << " ---" << "\033[0m" << std::endl;
}

int main() {
	printTitle("Creating Intern and Bureaucrat");
	Intern intern;
	Bureaucrat highB("Batu", 1);
	
	std::cout << highB << std::endl;

	AForm *form1;
	AForm *form2;
	AForm *form3;
	AForm *form4;

	printTitle("Intern Making Forms");
	try {
		form1 = intern.makeForm("robotomy request", "robotomy");
		form2 = intern.makeForm("shrubbery creation", "shrubbery");
		form3 = intern.makeForm("presidential pardon", "presidential");
		form4 = intern.makeForm("unknown form", "target");
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Bureaucrat Signing Forms");
	try {
		highB.signForm(*form1);
		highB.signForm(*form2);
		highB.signForm(*form3);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	printTitle("Bureaucrat Executing Forms");
	try {
		highB.executeForm(*form1);
		highB.executeForm(*form2);
		highB.executeForm(*form3);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	delete form1;
	delete form2;
	delete form3;
	delete form4;

	return (0);
}
