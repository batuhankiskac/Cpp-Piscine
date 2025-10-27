#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

const std::string treeArt =
"              v .   ._, |_  .,\n"
"           `-._\\/  .  \\ /    |/_\n"
"               \\  _\\, y | \\/\\/\n"
"         _\\_.___\\, \\/ -.\\||\n"
"           `7-,--.`._||  / / ,\n"
"           /'     `-. `./ / |/_.\'\n"
"                     |    |\/\/\n"
"                     |_    /\n"
"                     |-   |\n"
"                     |   =|\n"
"                     |    |\n"
"--------------------/ ,  . \\--------._\n\n";

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("default") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) { }

ShrubberyCreationForm::~ShrubberyCreationForm() { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return (this->_target);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream outFile((_target + "_shrubbery").c_str());

	if (!outFile || outFile.fail()) {
		std::cerr << "Error: Could not create or write to file." << std::endl;
		return;
	}

	outFile << treeArt;
	outFile << treeArt;
	outFile << treeArt;
	outFile.close();
}
