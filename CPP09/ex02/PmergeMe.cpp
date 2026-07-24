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

int PmergeMe::parsePositiveInteger(const std::string& arg) const {
	if (arg.empty()) {
		throw std::runtime_error("Error");
	}

	long value = 0;
	for (size_t i = 0; i < arg.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(arg[i]))) {
			throw std::runtime_error("Error");
		}
		int digit = arg[i] - '0';
		if (value > (INT_MAX - digit) / 10) {
			throw std::runtime_error("Error");
		}
		value = value * 10 + digit;
	}
	if (value == 0) {
		throw std::runtime_error("Error");
	}
	return static_cast<int>(value);
}

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

void PmergeMe::sortVector(std::vector<int>& arr) {
	if (arr.size() <= 1) return;

	int remainder = -1;
	if (arr.size() % 2 != 0) {
		remainder = arr.back();
		arr.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> winners;

	for (size_t i = 0; i < arr.size(); i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b) {
			pairs.push_back(std::make_pair(a, b));
			winners.push_back(a);
		} else {
			pairs.push_back(std::make_pair(b, a));
			winners.push_back(b);
		}
	}

	sortVector(winners);

	std::vector<int> losers;
	std::vector<int> partners;
	std::vector<bool> paired(pairs.size(), false);
	for (size_t i = 0; i < winners.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (!paired[j] && pairs[j].first == winners[i]) {
				losers.push_back(pairs[j].second);
				partners.push_back(pairs[j].first);
				paired[j] = true;
				break;
			}
		}
	}

	if (!losers.empty()) {
		winners.insert(winners.begin(), losers[0]);
	}

	size_t jacobIndex = 3;
	size_t prevJacob = 1;
	size_t insertedCount = 1;

	while (insertedCount < losers.size()) {
		size_t currentJacob = getJacobsthal(jacobIndex);
		size_t limit = currentJacob;

		if (limit > losers.size())
			limit = losers.size();

		for (size_t i = limit; i > prevJacob; --i) {
			int val = losers[i - 1];
			int partner = partners[i - 1];

			std::vector<int>::iterator end_it = std::find(winners.begin(), winners.end(), partner);
			std::vector<int>::iterator pos = std::lower_bound(winners.begin(), end_it, val);

			winners.insert(pos, val);
		}

		insertedCount += (limit - prevJacob);
		prevJacob = currentJacob;
		jacobIndex++;
	}

	if (remainder != -1) {
		std::vector<int>::iterator pos = std::lower_bound(winners.begin(), winners.end(), remainder);
		winners.insert(pos, remainder);
	}

	arr = winners;
}
void PmergeMe::sortDeque(std::deque<int>& arr) {
	if (arr.size() <= 1) return;

	int remainder = -1;
	if (arr.size() % 2 != 0) {
		remainder = arr.back();
		arr.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> winners;

	for (size_t i = 0; i < arr.size(); i += 2) {
		int a = arr[i];
		int b = arr[i + 1];
		if (a > b) {
			pairs.push_back(std::make_pair(a, b));
			winners.push_back(a);
		} else {
			pairs.push_back(std::make_pair(b, a));
			winners.push_back(b);
		}
	}

	sortDeque(winners);

	std::deque<int> losers;
	std::deque<int> partners;
	std::deque<bool> paired(pairs.size(), false);
	for (size_t i = 0; i < winners.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (!paired[j] && pairs[j].first == winners[i]) {
				losers.push_back(pairs[j].second);
				partners.push_back(pairs[j].first);
				paired[j] = true;
				break;
			}
		}
	}

	if (!losers.empty()) {
		winners.insert(winners.begin(), losers[0]);
	}

	size_t jacobIndex = 3;
	size_t prevJacob = 1;
	size_t insertedCount = 1;

	while (insertedCount < losers.size()) {
		size_t currentJacob = getJacobsthal(jacobIndex);
		size_t limit = currentJacob;
		if (limit > losers.size()) limit = losers.size();

		for (size_t i = limit; i > prevJacob; --i) {
			int val = losers[i - 1];
			int partner = partners[i - 1];
			std::deque<int>::iterator end_it = std::find(winners.begin(), winners.end(), partner);
			std::deque<int>::iterator pos = std::lower_bound(winners.begin(), end_it, val);
			winners.insert(pos, val);
		}
		insertedCount += (limit - prevJacob);
		prevJacob = currentJacob;
		jacobIndex++;
	}

	if (remainder != -1) {
		std::deque<int>::iterator pos = std::lower_bound(winners.begin(), winners.end(), remainder);
		winners.insert(pos, remainder);
	}

	arr = winners;
}

void PmergeMe::execute(int argc, char **argv) {
	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i) {
		parsePositiveInteger(argv[i]);
	}

	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i) {
		std::cout << parsePositiveInteger(argv[i]) << " ";
	}
	std::cout << "\n";

	std::clock_t startVec = std::clock();
	for (int i = 1; i < argc; ++i) {
		vec.push_back(parsePositiveInteger(argv[i]));
	}
	sortVector(vec);
	std::clock_t endVec = std::clock();
	double microsecondsVec = (endVec - startVec) / static_cast<double>(CLOCKS_PER_SEC) * 1000000;

	std::clock_t startDeq = std::clock();
	for (int i = 1; i < argc; ++i) {
		deq.push_back(parsePositiveInteger(argv[i]));
	}
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
