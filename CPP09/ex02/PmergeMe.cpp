#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() { }

size_t PmergeMe::getJacobsthal(size_t n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	size_t prev2 = 0;
	size_t prev1 = 1;
	size_t current = 0;

	for (size_t i = 2; i <= n; ++i) {
		current = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = current;
	}

	return current;
}

void PmergeMe::execute(int argc, char **argv) {
	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);

		for (size_t j = 0; j < arg.size(); ++j) {
			if (!std::isdigit(arg[j])) {
				std::cerr << "Error\n";
				return;
			}
		}

		int value = std::atoi(arg.c_str());
		vec.push_back(value);
		deq.push_back(value);
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";

	std::clock_t startVec = std::clock();
	sortVector(vec);
	std::clock_t endVec = std::clock();
	double microsecondsVec = (endVec - startVec) / static_cast<double>(CLOCKS_PER_SEC) * 1000000;

	std::clock_t startDeq = std::clock();
	sortDeque(deq);
	std::clock_t endDeq = std::clock();
	double microsecondsDeq = (endDeq - startDeq) / static_cast<double>(CLOCKS_PER_SEC) * 1000000;

	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << microsecondsVec << " us\n";
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << microsecondsDeq << " us\n";
}
