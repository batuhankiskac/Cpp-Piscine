#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return (*this);
}

const std::string& AForm::getName() const {
	return (this->_name);
}

bool AForm::isSigned() const {
	return (this->_signed);
}

int AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("AForm Error: Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("AForm Error: Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("AForm Error: Form not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "--- AForm Information ---" << "\n"
	   << "  Name: " << form.getName() << "\n"
	   << "  Signed: " << (form.isSigned() ? "Yes" : "No") << "\n"
	   << "  Grade to Sign: " << form.getGradeToSign() << "\n"
	   << "  Grade to Execute: " << form.getGradeToExecute();
	return (os);
}
