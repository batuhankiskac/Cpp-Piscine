#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return (*this);
}

const std::string& Form::getName() const {
	return (this->_name);
}

bool Form::isSigned() const {
	return (this->_signed);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form Error: Grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form Error: Grade too low");
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "--- Form Information ---" << "\n"
	   << "  Name: " << form.getName() << "\n"
	   << "  Signed: " << (form.isSigned() ? "Yes" : "No") << "\n"
	   << "  Grade to Sign: " << form.getGradeToSign() << "\n"
	   << "  Grade to Execute: " << form.getGradeToExecute();
	return (os);
}
