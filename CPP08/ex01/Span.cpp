#include "Span.hpp"

Span::Span() : N(0) { }

Span::Span(unsigned int N) : N(N) { }

Span::~Span() { }

Span::Span(const Span& other) : N(other.N), numbers(other.numbers) { }

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}

int Span::shortestSpan() const {
	if (numbers.size() < 2)
		throw EmptyNumbersException();

	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (numbers.size() < 2)
		throw EmptyNumbersException();

	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());

	return max - min;
}

void Span::addNumber(int number) {
	if (numbers.size() >= N)
		throw SpanFullException();
	numbers.push_back(number);
}
