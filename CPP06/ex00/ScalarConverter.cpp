#include "ScalarConverter.hpp"

e_type ScalarConverter::detectType(const std::string &str) {
	if (str.empty())
		return TOKEN_INVALID;

	if (str == "-inff" || str == "+inff" || str == "nanf")
		return TOKEN_FLOAT;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return TOKEN_DOUBLE;

	if (str.length() == 1 && !std::isdigit(str[0]))
		return TOKEN_CHAR;

	bool containF = false;
	bool containDot = false;
	bool containSign = false;
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] == '-' || str[i] == '+') {
			if (i != 0)
				return TOKEN_INVALID;
			containSign = true;
		} else if (std::isdigit(str[i])) {
			continue;
		} else if (str[i] == '.') {
			if (containDot)
				return TOKEN_INVALID;
			containDot = true;
		} else if (str[i] == 'f') {
			if (i != str.length() - 1)
				return TOKEN_INVALID;
			containF = true;
		} else {
			return TOKEN_INVALID;
		}
	}

	if (containF) {
		if (containDot || (!containDot && containF))
			return TOKEN_FLOAT;
		return TOKEN_INVALID;
	}
	if (containDot)
		TOKEN_DOUBLE;
	return TOKEN_INT;
}

void ScalarConverter::printChar(char c) {
	std::cout << "char: ";
	if (std::isprint(c))
		std::cout << "'" << c << "'\n";
	else
		std:: cout << "Non displayable\n";

	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::printInt(int i) {
	std::cout << "char: ";
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "impossible\n";
	else if (!std::isprint(i))
		std:: cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(i) << "'\n";

	std::cout << "int: "<< i << "\n";
	std::cout << "float: " << static_cast<float>(i) << ".0f\n";
	std::cout << "double: " << static_cast<double>(i) << ".0\n";
}

void ScalarConverter::printFloat(float f) {
	std::cout << "char: ";
	if (std::isnan(f) || std::isinf(f) ||
		f < std::numeric_limits<char>::min() ||
		f > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(f))) {
		std:: cout << "Non displayable\n";
	} else {
		std::cout << "'" << static_cast<char>(f) << "'\n";
	}

	std::cout << "int: ";
	if (std::isnan(f) || std::isinf(f) ||
		static_cast<long>(f) < std::numeric_limits<int>::min() ||
		static_cast<long>(f) > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(f) << "\n";
	}

	std::cout << "float: " << f;
	if (!std::isnan(f) && !std::isinf(f) && (f == std::floor(f)))
		std::cout << ".0";
	std::cout << "f\n";

	std::cout << "double: " << static_cast<double>(f);
	if (!std::isnan(f) && !std::isinf(f) && (f == std::floor(f)))
		std::cout << ".0";
	std::cout << "f\n";
}

void ScalarConverter::printDouble(double d) {
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) ||
		d < std::numeric_limits<char>::min() ||
		d > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(d))) {
		std:: cout << "Non displayable\n";
	} else {
		std::cout << "'" << static_cast<char>(d) << "'\n";
	}

	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) ||
		static_cast<long>(d) < std::numeric_limits<int>::min() ||
		static_cast<long>(d) > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std::endl;
	} else {
		std::cout << static_cast<int>(d) << "\n";
	}

	std::cout << "float: " << static_cast<float>(d);
	if (!std::isnan(d) && !std::isinf(d) && (d == std::floor(d)))
		std::cout << ".0";
	std::cout << "f\n";

	std::cout << "double: " << d;
	if (!std::isnan(d) && !std::isinf(d) && (d == std::floor(d)))
		std::cout << ".0";
	std::cout << "\n";
}

void ScalarConverter::convert(const std::string &str)
{
	e_type type = detectType(str);

	switch (type) {
		case TOKEN_CHAR:
			printChar(str[0]);
			break;

		case TOKEN_INT:
			printInt(std::atoi(str.c_str()));
			break;

		case TOKEN_FLOAT:
			printFloat(std::strtof(str.c_str(), NULL));
			break;

		case TOKEN_DOUBLE:
			printDouble(std::strtod(str.c_str(), NULL));
			break;

		default:
			std::cerr << "Error: Invalid token type.\n";
			break;
	}
}
