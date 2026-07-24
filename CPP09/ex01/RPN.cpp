#include "Rpn.hpp"

Rpn::Rpn() { }

Rpn::Rpn(const Rpn& other) { (void)other; }

Rpn& Rpn::operator=(const Rpn& other) {
	(void)other;
	return *this;
}

Rpn::~Rpn() { }

bool Rpn::isOperator(const std::string& token) const {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool Rpn::isNumber(const std::string& token) const {
	if (token.length() == 1 && std::isdigit(token[0])) {
		return true;
	}

	if (token.length() == 2 && token[0] == '-' && std::isdigit(token[1])) {
		return true;
	}
	return false;
}

double Rpn::applyOperator(char op, double a, double b) const {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0) {
				throw std::runtime_error("Error");
			}
			return a / b;
		default:
			throw std::runtime_error("Error");
	}
	return 0;
}

double Rpn::calculate(const std::string& str) const {
	std::stack<double> stack;
	std::istringstream ss(str);
	std::string token;

	while (ss >> token) {
		if (isNumber(token)) {
			double value = std::atof(token.c_str());
			if (value >= 10 || value <= -10) {
				throw std::runtime_error("Error");
			}
			stack.push(std::atof(token.c_str()));
		} else if (isOperator(token)) {
			if (stack.size() < 2) {
				throw std::runtime_error("Error");
			}
			double b = stack.top(); stack.pop();
			double a = stack.top(); stack.pop();
			double result = applyOperator(token[0], a, b);
			stack.push(result);
		} else {
			throw std::runtime_error("Error");
		}
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Error");
	}
	return stack.top();
}
