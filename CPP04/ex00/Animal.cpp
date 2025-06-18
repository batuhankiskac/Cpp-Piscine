#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const std::string &type) : type(type) {
	std::cout << "Animal constructor called for type: " << type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal copy constructor called for type: " << type << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called for type: " << type << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
		std::cout << "Animal assignment operator called for type: " << type << std::endl;
	}
	return (*this);
}

void Animal::makeSound() const {
	std::cout << "Animal makes a sound." << std::endl;
}

std::string Animal::getType() const {
	return (type);
}
