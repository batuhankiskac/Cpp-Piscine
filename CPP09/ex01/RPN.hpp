#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
private:
	bool isOperator(const std::string& token) const;
	bool isNumber(const std::string& token) const;
	double applyOperator(char op, double a, double b) const;

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	double calculate(const std::string& str) const;
};

#endif
