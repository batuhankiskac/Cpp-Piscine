#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void printTitle(std::string title)
{
	std::cout << "\n" << "\033[1;36m" << "--- " << title << " ---" << "\033[0m" << std::endl;
}

int main() {
	printTitle("Creating Bureaucrats");
	Bureaucrat lowB("LowGrade", 150);
	Bureaucrat midB("MidGrade", 75);
	Bureaucrat highB("HighGrade", 1);

	std::cout << lowB << std::endl;
	std::cout << midB << std::endl;
	std::cout << highB << std::endl;

	ShrubberyCreationForm shrubForm("shrubbery");
	RobotomyRequestForm robotForm("robotomy");
	PresidentialPardonForm pardonForm("pardon");

	printTitle("Test 1: ShrubberyCreationForm");
	lowB.signForm(shrubForm);
	lowB.executeForm(shrubForm);
	midB.executeForm(shrubForm);

	printTitle("Test 2: RobotomyRequestForm");
	midB.executeForm(robotForm);
	midB.signForm(robotForm);
	midB.executeForm(robotForm);
	midB.executeForm(robotForm);
	midB.executeForm(robotForm);
	midB.executeForm(robotForm);
	midB.executeForm(robotForm);

	printTitle("Test 3: PresidentialPardonForm");
	highB.executeForm(pardonForm);
	midB.signForm(pardonForm);
	highB.signForm(pardonForm);
	highB.executeForm(pardonForm);

	return (0);
}
