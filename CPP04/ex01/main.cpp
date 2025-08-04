#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1: Deep Copy Verification ---" << std::endl;
	{
		std::cout << "--> Creating an original Cat and giving it an idea." << std::endl;
		Cat* original = new Cat();
		original->setIdea(0, "I should chase that red dot.");

		std::cout << "\n--> Creating a copy of the original Cat using the copy constructor." << std::endl;
		Cat* copy = new Cat(*original);

		std::cout << "\n--> Initial ideas:" << std::endl;
		std::cout << "    Original Cat's Idea: " << original->getIdea(0) << std::endl;
		std::cout << "    Copied Cat's Idea:   " << copy->getIdea(0) << std::endl;

		std::cout << "\n--> Changing the original Cat's idea..." << std::endl;
		original->setIdea(0, "Maybe I'll take a nap instead.");

		std::cout << "\n--> Verifying that the copy's idea has NOT changed (Proof of Deep Copy):" << std::endl;
		std::cout << "    Original Cat's Idea: " << original->getIdea(0) << std::endl;
		std::cout << "    Copied Cat's Idea:   " << copy->getIdea(0) << std::endl;

		std::cout << "\n--> Deleting both cats. If this doesn't crash, deep copy is working correctly." << std::endl;
		delete original;
		delete copy;
	}

	std::cout << "\n//------------------------------------------------------------------//\n" << std::endl;

	std::cout << "--- Test 2: Polymorphic Array and Virtual Destructors ---" << std::endl;
	{
		const int animalCount = 4;
		Animal* animals[animalCount];

		std::cout << "--> Creating a polymorphic array of Animals (half Dogs, half Cats)..." << std::endl;
		for (int i = 0; i < animalCount; ++i)
		{
			if (i < animalCount / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
			std::cout << "---" << std::endl;
		}

		std::cout << "\n--> Deleting the array using base class pointers..." << std::endl;
		std::cout << "    (Virtual destructor ensures Cat/Dog AND their Brains are deleted)" << std::endl;
		for (int i = 0; i < animalCount; ++i)
		{
			delete animals[i];
			std::cout << "---" << std::endl;
		}
	}

	std::cout << "\n--- End of main ---" << std::endl;
	return (0);
}
