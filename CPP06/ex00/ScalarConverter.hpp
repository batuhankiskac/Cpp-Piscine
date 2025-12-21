#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter {
private:
	ScalarConverter() { }
	ScalarConverter(const ScalarConverter &other) { (void)other; }
	~ScalarConverter() { }
	ScalarConverter& operator=(const ScalarConverter &other) { (void)other; return *this; }
public:
	static void convert(const std::string &str);
};

#endif
