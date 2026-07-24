#include "RPN.hpp"
#include <cctype>
#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN() { }

RPN::RPN(const RPN& other) { (void)other; }

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

RPN::~RPN() { }

bool RPN::isOperator(const std::string& token) const {
	return token.length() == 1
		&& (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const {
	return (token.length() == 1
			&& std::isdigit(static_cast<unsigned char>(token[0])))
		|| (token.length() == 2 && token[0] == '-'
			&& std::isdigit(static_cast<unsigned char>(token[1])));
}

double RPN::applyOperator(char op, double a, double b) const {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			return a / b;
		default: throw std::runtime_error("Error");
	}
}

double RPN::calculate(const std::string& str) const {
	std::stack<double> values;
	std::istringstream stream(str);
	std::string token;

	while (stream >> token) {
		if (isNumber(token)) {
			double value = token[token.length() - 1] - '0';
			values.push(token[0] == '-' ? -value : value);
		}
		else if (isOperator(token)) {
			if (values.size() < 2)
				throw std::runtime_error("Error");
			const double b = values.top();
			values.pop();
			const double a = values.top();
			values.pop();
			values.push(applyOperator(token[0], a, b));
		}
		else
			throw std::runtime_error("Error");
	}

	if (values.size() != 1)
		throw std::runtime_error("Error");
	return values.top();
}
