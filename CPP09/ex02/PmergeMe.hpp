#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

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
};

#endif
