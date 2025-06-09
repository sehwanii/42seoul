#pragma once

#include <deque>

class Span {
	private:
		unsigned int	_max;
		std::deque<int>	_data;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span &operator=(const Span& other);
		~Span();

		void	addNumber(int value);
		void	fillAll(void);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	printAll(void) const;
};
