#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &other);
		~Dog();

		Dog &operator=(const Dog &other);

		void makeSound() const;

		std::string getIdea(int index) const;
		void setIdea(int index, const std::string &idea);
};

#endif
