#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cctype>

enum e_type {
	TOKEN_CHAR,
	TOKEN_INT,
	TOKEN_FLOAT,
	TOKEN_DOUBLE,
	TOKEN_INVALID
};

class ScalarConverter {
private:
	ScalarConverter() { }
	ScalarConverter(const ScalarConverter &other) { (void)other; }
	~ScalarConverter() { }
	ScalarConverter& operator=(const ScalarConverter &other) { (void)other; return *this; }

	static e_type detectType(const std::string& str);
	static void printChar(char c);
	static void printInt(int i);
	static void printFloat(float f);
	static void printDouble(double d);
public:
	static void convert(const std::string &str);
};

#endif
