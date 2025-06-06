#include <iostream>
#include <string>

int main() {
	std::string brainString = "HI THIS IS BRAIN";
	std::string* brainPTR = &brainString;
	std::string& brainREF = brainString;

	std::cout << "The memory address of the string variable: " << &brainString << std::endl;
	std::cout << "The memory address held by brainPTR: " << brainPTR << std::endl;
	std::cout << "The memory address held by brainREF: " << &brainREF << std::endl << std::endl;

	std::cout << "The value of the string variable: " << brainString << std::endl;
	std::cout << "The value pointed to by brainPTR: " << *brainPTR << std::endl;
	std::cout << "The value pointed to by brainREF: " << brainREF << std::endl;
	return (0);
}

