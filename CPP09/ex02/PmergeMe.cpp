#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() { }

int PmergeMe::parsePositiveInteger(const std::string& arg) const {
	if (arg.empty())
		throw std::runtime_error("Error");

	long value = 0;
	for (size_t i = 0; i < arg.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(arg[i])))
			throw std::runtime_error("Error");
		const int digit = arg[i] - '0';
		if (value > (INT_MAX - digit) / 10)
			throw std::runtime_error("Error");
		value = value * 10 + digit;
	}
	if (value == 0)
		throw std::runtime_error("Error");
	return static_cast<int>(value);
}

size_t PmergeMe::getJacobsthal(size_t n) const {
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
	if (arr.size() <= 1)
		return;

	int remainder = -1;
	if (arr.size() % 2 != 0) {
		remainder = arr.back();
		arr.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> winners;

	for (size_t i = 0; i < arr.size(); i += 2) {
		int winner = arr[i];
		int loser = arr[i + 1];
		if (winner < loser)
			std::swap(winner, loser);
		pairs.push_back(std::make_pair(winner, loser));
		winners.push_back(winner);
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

	if (!losers.empty())
		winners.insert(winners.begin(), losers[0]);

	size_t jacobIndex = 3;
	size_t prevJacob = 1;

	while (prevJacob < losers.size()) {
		const size_t limit = std::min(getJacobsthal(jacobIndex), losers.size());
		for (size_t i = limit; i > prevJacob; --i) {
			const int value = losers[i - 1];
			std::vector<int>::iterator end =
				std::find(winners.begin(), winners.end(), partners[i - 1]);
			winners.insert(std::lower_bound(winners.begin(), end, value), value);
		}
		prevJacob = limit;
		++jacobIndex;
	}

	if (remainder != -1)
		winners.insert(std::lower_bound(winners.begin(), winners.end(), remainder),
			remainder);

	arr = winners;
}

void PmergeMe::sortDeque(std::deque<int>& arr) {
	if (arr.size() <= 1)
		return;

	int remainder = -1;
	if (arr.size() % 2 != 0) {
		remainder = arr.back();
		arr.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> winners;

	for (size_t i = 0; i < arr.size(); i += 2) {
		int winner = arr[i];
		int loser = arr[i + 1];
		if (winner < loser)
			std::swap(winner, loser);
		pairs.push_back(std::make_pair(winner, loser));
		winners.push_back(winner);
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

	if (!losers.empty())
		winners.insert(winners.begin(), losers[0]);

	size_t jacobIndex = 3;
	size_t prevJacob = 1;

	while (prevJacob < losers.size()) {
		const size_t limit = std::min(getJacobsthal(jacobIndex), losers.size());
		for (size_t i = limit; i > prevJacob; --i) {
			const int value = losers[i - 1];
			std::deque<int>::iterator end =
				std::find(winners.begin(), winners.end(), partners[i - 1]);
			winners.insert(std::lower_bound(winners.begin(), end, value), value);
		}
		prevJacob = limit;
		++jacobIndex;
	}

	if (remainder != -1)
		winners.insert(std::lower_bound(winners.begin(), winners.end(), remainder),
			remainder);

	arr = winners;
}

void PmergeMe::execute(int argc, char **argv) {
	std::vector<int> input;
	for (int i = 1; i < argc; ++i)
		input.push_back(parsePositiveInteger(argv[i]));

	std::cout << "Before: ";
	for (size_t i = 0; i < input.size(); ++i)
		std::cout << input[i] << " ";
	std::cout << std::endl;

	std::vector<int> vec;
	const std::clock_t startVec = std::clock();
	vec = input;
	sortVector(vec);
	const double vectorTime = (std::clock() - startVec)
		* 1000000.0 / CLOCKS_PER_SEC;

	std::deque<int> deq;
	const std::clock_t startDeq = std::clock();
	deq.assign(input.begin(), input.end());
	sortDeque(deq);
	const double dequeTime = (std::clock() - startDeq)
		* 1000000.0 / CLOCKS_PER_SEC;

	std::cout << "After:  ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5)
		<< "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << vectorTime << " us\n"
		<< "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << dequeTime << " us\n";
}
