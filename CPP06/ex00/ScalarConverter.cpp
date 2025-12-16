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
