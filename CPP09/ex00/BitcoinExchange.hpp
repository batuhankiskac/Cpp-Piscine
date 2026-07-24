#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double> rates;

	bool isValidDate(const std::string& date) const;
	bool parseValue(const std::string& text, double& value) const;
	std::string trim(const std::string& str) const;
	void processLine(const std::string& line) const;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void execute(const std::string& file) const;
};

#endif
