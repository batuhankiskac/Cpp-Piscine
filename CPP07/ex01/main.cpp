#include "iter.hpp"
#include <iostream>

void printString(std::string &str) {
	std::cout << str << std::endl;
}

int main() {
	std::string arr[3];

	arr[0] = "Cat said some wise words: Meow.";
	arr[1] = "Cat said some more wise words: Purr.";
	arr[2] = "Cat said the wisest words of all: Meow Purr Meow.";

	iter(arr, 3, printString);
}
