#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate() {
	int random = std::rand() % 3;

	switch (random) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown\n";
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch (...) { }

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (...) { }

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (...) { }

	std::cout << "Unknown\n";
}

int main() {
	std::srand(std::time(NULL));

	for (int i = 0; i < 10; ++i) {
		Base *base = generate();

		std::cout << "Identification by pointer: ";
		identify(base);
		std::cout << "Identification by reference: ";
		identify(*base);

		delete base;
	}
	return 0;
}
