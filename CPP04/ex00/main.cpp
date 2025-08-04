#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Test 1: Correct Polymorphism with 'virtual' ---" << std::endl;
	{
		std::cout << "--> Creating derived objects and storing them in base pointers..." << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\n--> Checking types:" << std::endl;
		std::cout << "Object 'meta' is of type: " << meta->getType() << std::endl;
		std::cout << "Object 'i' is of type: " << i->getType() << std::endl;
		std::cout << "Object 'j' is of type: " << j->getType() << std::endl;

		std::cout << "\n--> Calling makeSound():" << std::endl;
		std::cout << "i (a Cat) -> ";
		i->makeSound();
		std::cout << "j (a Dog) -> ";
		j->makeSound();
		std::cout << "meta (an Animal) -> ";
		meta->makeSound();

		std::cout << "\n--> Deleting objects..." << std::endl;
		delete meta;
		delete j;
		delete i;
	}

	std::cout << "\n//------------------------------------------------------------------//\n" << std::endl;

	std::cout << "--- Test 2: Incorrect Behavior without 'virtual' ---" << std::endl;
	{
		std::cout << "--> Creating a WrongCat and storing it in a WrongAnimal pointer..." << std::endl;
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();

		std::cout << "\n--> Checking types:" << std::endl;
		std::cout << "Object 'wrongMeta' is of type: " << wrongMeta->getType() << std::endl;
		std::cout << "Object 'wrongCat' is of type: " << wrongCat->getType() << std::endl;

		std::cout << "\n--> Calling makeSound():" << std::endl;
		std::cout << "wrongCat -> ";
		wrongCat->makeSound();
		std::cout << "wrongMeta -> ";
		wrongMeta->makeSound();

		std::cout << "\n--> Deleting objects..." << std::endl;
		delete wrongMeta;
		delete wrongCat;
	}

	std::cout << "\n--- End of main ---" << std::endl;
	return (0);
}
