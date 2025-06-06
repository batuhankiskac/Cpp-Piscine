#include <iostream>
#include <fstream>
#include <string>

static bool processFile(const std::string &inputFile,
						const std::string &outputFile,
						const std::string &s1,
						const std::string &s2)
{
	std::ifstream input(inputFile);
	if (!input.is_open()) {
		std::cerr << "Error: Could not open file " << inputFile << std::endl;
		return (false);
	}

	std::ofstream output(outputFile);
	if (!output.is_open()) {
		std::cerr << "Error: Could not open file " << outputFile << std::endl;
		input.close();
		return (false);
	}

	std::string line;
	while (std::getline(input, line)) {
		std::string modifiedLine;
		size_t pos = 0;
		size_t found;
		while ((found = line.find(s1, pos)) != std::string::npos) {
			modifiedLine.append(line, pos, found - pos);
			modifiedLine += s2;
			pos = found + s1.length();
		}
		modifiedLine.append(line, pos, line.length() - pos);
		output << modifiedLine << std::endl;
	}
	input.close();
	output.close();
	return (true);
}

int main (int argc, const char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string inputFile = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty()) {
		std::cerr << "Error: The s1 cannot be empty." << std::endl;
		return (1);
	}

	std::string outputFile = inputFile + ".replace";

	if (!processFile(inputFile, outputFile, s1, s2))
		return (1);
	return (0);
}
