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
	void insertVector(std::vector<int>& mainChain, int value);

	void sortDeque(std::deque<int>& arr);
	void insertDeque(std::deque<int>& mainChain, int value);

	size_t getJacobsthal(size_t n);
};

#endif
