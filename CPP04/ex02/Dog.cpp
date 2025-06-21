#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	brain = new Brain();
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
		std::cout << "Dog assignment operator called." << std::endl;
	}
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea(int index) const {
	if (index >= 0 && index < 100)
		return (brain->ideas[index]);
	else
		return ("Invalid index! Ideas range from 0 to 99.");
}

void Dog::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		brain->ideas[index] = idea;
		std::cout << "Dog idea [" << index << "] set to: " << idea << std::endl;
	} else {
		std::cout << "Dog: Invalid index! Ideas range from 0 to 99." << std::endl;
	}
}
