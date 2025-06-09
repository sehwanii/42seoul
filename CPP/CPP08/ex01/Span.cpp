#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <ctime>
#include <limits>

/* ======================== Orthodox Canonical Form ========================= */
Span::Span() {}

Span::Span(unsigned int N) : _max(N) {}

Span::Span(const Span& other) {
	this->_max = other._max;
	this->_data.clear();
	for (std::deque<int>::const_iterator it = other._data.begin(); it != other._data.end(); ++it)
		this->_data.push_back(*it);
}

Span &Span::operator=(const Span& other) {
	if (this != &other) {
		this->_max = other._max;
		this->_data.clear();
		for (std::deque<int>::const_iterator it = other._data.begin(); it != other._data.end(); ++it)
			this->_data.push_back(*it);
	}
	return *this;
}

Span::~Span() {}

/* =============================== Functions ================================ */
void Span::addNumber(int value) {
	if (this->_data.size() == this->_max)
		throw std::length_error("Error: maximum size reached");
	this->_data.push_back(value);
}

void Span::fillAll(void) {
	std::srand(std::time(0));
	for (unsigned int i = 0; i < this->_max - this->_data.size(); i++) {
		this->_data.push_back(std::rand());
	}
}

int Span::shortestSpan(void) {
	if (this->_data.size() < 2)
		throw std::logic_error("Error: size must be at least 2");
	std::sort(this->_data.begin(), this->_data.end());
	int min = std::numeric_limits<int>::max();
	int span;
	for (std::deque<int>::const_iterator it = this->_data.begin(); it != this->_data.end() - 1; ++it) {
		span = std::abs(*it - *(it + 1));
		if (span < min)
			min = span;
	}
	return min;
}

int Span::longestSpan(void) {
	if (this->_data.size() < 2)
		throw std::logic_error("Error: size must be at least 2");
	std::sort(this->_data.begin(), this->_data.end());
	return this->_data.back() - this->_data.front();
}

void Span::printAll(void) const {
	for (std::deque<int>::const_iterator it = this->_data.begin(); it != this->_data.end() - 1; ++it) {
		std::cout << *it;
		if (it != this->_data.end() - 2)
			std::cout << ", ";
	}
	std::cout << "\n";
}