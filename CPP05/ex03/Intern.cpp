#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() { }

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		(void)other;
	}
	return (*this);
}

Intern::~Intern() { }

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	const std::string formNames[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};

	AForm *newForm = NULL;

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0:
					newForm = new RobotomyRequestForm(target);
					break;
				case 1:
					newForm = new ShrubberyCreationForm(target);
					break;
				case 2:
					newForm = new PresidentialPardonForm(target);
					break;
			}
			break;
		}
	}

	if (newForm == NULL) {
		std::cout << "Intern Error: Invalid form name" << std::endl;
	}
	return (newForm);
}