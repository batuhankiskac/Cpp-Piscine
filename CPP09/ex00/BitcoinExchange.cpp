#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	std::string line;

	if (!file.is_open()) {
		throw std::runtime_error("Could not open database file.");
	}

	std::getline(file, line);

	while (std::getline(file, line)) {
		if (line.empty()) continue;

		std::string date;
		std::string rateStr;
		size_t commaPos = line.find(',');
		if (commaPos != std::string::npos) {
			date = line.substr(0, commaPos);
			rateStr = line.substr(commaPos + 1);
			this->rates[date] = std::strtod(rateStr.c_str(), NULL);
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	rates = other.rates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		rates = other.rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}
	for (size_t i = 0; i < date.length(); ++i) {
		if (i != 4 && i != 7
			&& !std::isdigit(static_cast<unsigned char>(date[i]))) {
			return false;
		}
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}

	int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
		daysInMonth[2] = 29;
	}

	return day <= daysInMonth[month];
}

std::string BitcoinExchange::trim(const std::string& str) const {
	size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos) return "";
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

void BitcoinExchange::processLine(const std::string& line) const {
	size_t pipePos = line.find('|');
	if (pipePos == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string date = trim(line.substr(0, pipePos));
	std::string valueStr = trim(line.substr(pipePos + 1));

	if (!isValidDate(date)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}

	char *endPtr;
	double value = std::strtod(valueStr.c_str(), &endPtr);
	if (valueStr.empty() || *endPtr != '\0' || value != value) {
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

	std::map<std::string, double>::const_iterator it = rates.lower_bound(date);

	if (it == rates.begin()) {
		if (it->first != date) {
			 std::cerr << "Error: no data available for date => " << date << std::endl;
			 return;
		}
	} else if (it == rates.end() || it->first != date) {
		--it;
	}

	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::execute(const std::string& file) const {
	std::ifstream input(file.c_str());
	std::string line;

	if (!input.is_open()) {
		throw std::runtime_error("Error: could not open file.");
	}

	std::getline(input, line);

	while (std::getline(input, line)) {
		if (line.empty()) continue;
		processLine(line);
	}
	input.close();
}
