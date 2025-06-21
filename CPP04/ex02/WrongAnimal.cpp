#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type(type) {
	std::cout << "WrongAnimal constructor called for type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "WrongAnimal copy constructor called for type: " << type << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called for type: " << type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		type = other.type;
		std::cout << "WrongAnimal assignment operator called for type: " << type << std::endl;
	}
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makes a sound." << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}
