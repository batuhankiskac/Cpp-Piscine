#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static bool initSeed() {
	static bool isSeeded = false;

	if (!isSeeded) {
		std::srand(std::time(NULL));
		isSeeded = true;
	}
	return (isSeeded);
}

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), _target("default") {
	initSeed();
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", 72, 45), _target(target) {
	initSeed();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {
	initSeed();
}

RobotomyRequestForm::~RobotomyRequestForm() { }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const {
	return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "*TRAK TAK TAK...*" << std::endl;

	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed for " << _target << "." << std::endl;
}
