#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Deep Copy Test ---" << std::endl;

	Cat* original = new Cat();
	original->setIdea(0, "I should chase that red dot.");

	Cat* copy = new Cat(*original);

	std::cout << "Original Cat's Idea: " << original->getIdea(0) << std::endl;
	std::cout << "Copied Cat's Idea:   " << copy->getIdea(0) << std::endl;

	std::cout << "\n-> Changing the original Cat's idea...\n" << std::endl;
	original->setIdea(0, "Maybe I'll take a nap instead.");

	std::cout << "Original Cat's Idea: " << original->getIdea(0) << std::endl;
	std::cout << "Copied Cat's Idea:   " << copy->getIdea(0) << std::endl;

	delete original;
	delete copy;

	std::cout << "\n--- Array Test ---" << std::endl;

	const int animalCount = 4;
	Animal* animals[animalCount];

	for (int i = 0; i < animalCount; ++i)
	{
		if (i < animalCount / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	for (int i = 0; i < animalCount; ++i)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	return (0);
}
