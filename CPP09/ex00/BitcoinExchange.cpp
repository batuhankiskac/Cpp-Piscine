#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Could not open database file.");

	std::getline(file, line);
	while (std::getline(file, line)) {
		const size_t comma = line.find(',');
		if (!line.empty() && comma != std::string::npos)
			rates[line.substr(0, comma)] =
				std::strtod(line.substr(comma + 1).c_str(), NULL);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: rates(other.rates) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		rates = other.rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); ++i) {
		if (i != 4 && i != 7
				&& !std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	const int year = std::atoi(date.substr(0, 4).c_str());
	const int month = std::atoi(date.substr(5, 2).c_str());
	const int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2
		&& ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		daysInMonth[2] = 29;
	return day <= daysInMonth[month];
}

bool BitcoinExchange::parseValue(const std::string& text, double& value) const {
	char *end;

	if (text.empty())
		return false;
	value = std::strtod(text.c_str(), &end);
	return *end == '\0' && value == value;
}

std::string BitcoinExchange::trim(const std::string& str) const {
	const size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
		return "";
	return str.substr(first, str.find_last_not_of(" \t") - first + 1);
}

void BitcoinExchange::processLine(const std::string& line) const {
	const size_t pipe = line.find('|');
	if (pipe == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}

	const std::string date = trim(line.substr(0, pipe));
	const std::string valueText = trim(line.substr(pipe + 1));
	double value;
	if (!isValidDate(date) || !parseValue(valueText, value)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return;
	}
	if (value > 1000.0) {
		std::cerr << "Error: too large a number." << std::endl;
		return;
	}

	std::map<std::string, double>::const_iterator rate = rates.upper_bound(date);
	if (rate == rates.begin()) {
		std::cerr << "Error: no data available for date => " << date << std::endl;
		return;
	}
	--rate;
	std::cout << date << " => " << value << " = "
		<< value * rate->second << std::endl;
}

void BitcoinExchange::execute(const std::string& file) const {
	std::ifstream input(file.c_str());
	std::string line;

	if (!input.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::getline(input, line);
	while (std::getline(input, line)) {
		if (!line.empty())
			processLine(line);
	}
}
