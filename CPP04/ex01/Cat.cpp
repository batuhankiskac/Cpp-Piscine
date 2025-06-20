#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	brain = new Brain();
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
		std::cout << "Cat assignment operator called." << std::endl;
	}
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return (brain->ideas[index]);
	else
		return ("Invalid index! Ideas range from 0 to 99.");
}

void Cat::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		brain->ideas[index] = idea;
		std::cout << "Cat idea [" << index << "] set to: " << idea << std::endl;
	} else {
		std::cout << "Cat: Invalid index! Ideas range from 0 to 99." << std::endl;
	}
}
