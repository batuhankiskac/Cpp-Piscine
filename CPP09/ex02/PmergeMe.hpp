#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <climits>
#include <stdexcept>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void execute(int argc, char **argv);
private:
	void sortVector(std::vector<int>& arr);
	void sortDeque(std::deque<int>& arr);

	size_t getJacobsthal(size_t n);
	int parsePositiveInteger(const std::string& arg) const;
};

#endif
