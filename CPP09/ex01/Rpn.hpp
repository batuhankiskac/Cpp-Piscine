#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <cstdlib>

class Rpn {
private:
	bool isOperator(const std::string& token) const;
	bool isNumber(const std::string& token) const;
	double applyOperator(char op, double a, double b) const;

public:
	Rpn();
	Rpn(const Rpn& other);
	Rpn& operator=(const Rpn& other);
	~Rpn();

	double calculate(const std::string& str) const;
};

#endif
