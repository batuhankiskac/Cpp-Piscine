#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
	double value = 0.0;
	char *endptr = NULL;

	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		value = static_cast<double>(literal[0]);
	} else {
		value = std::strtod(literal.c_str(), &endptr);
		if (*endptr != '\0' && std::string(endptr) != "f")
			value = std::numeric_limits<double>::quiet_NaN();
	}

	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";

	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value) ||
		value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";

	std::cout << "float: " << static_cast<float>(value);
	if (!std::isnan(value) && !std::isinf(value) && value == std::floor(value))
		std::cout << ".0";
	std::cout << "f\n";

	std::cout << "double: " << value;
	if (!std::isnan(value) && !std::isinf(value) && value == std::floor(value))
		std::cout << ".0";
	std::cout << "\n";
}
