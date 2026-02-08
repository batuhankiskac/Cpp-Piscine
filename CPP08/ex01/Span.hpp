#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
private:
	unsigned int N;
	std::vector<int> numbers;
public:
	Span();
	Span(unsigned int N);
	~Span();
	Span(const Span& other);
	Span& operator=(const Span& other);

	int shortestSpan() const;
	int longestSpan() const;
	void addNumber(int number);

	template <typename it>
	void addNumber(it begin, it end) {
		if (std::distance(begin, end) + numbers.size() > N)
			throw SpanFullException();
		numbers.insert(numbers.end(), begin, end);
	}

	class SpanFullException : public std::exception {
		const char* what() const throw() {
			return "Span is full! Cannot add more numbers.";
		}
	};

	class EmptyNumbersException : public std::exception {
		const char* what() const throw() {
			return "Not enough numbers to calculate span!";
		}
	};
};

#endif
