#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack& obj) {
			*this = obj;
		};
		MutantStack& operator=(const MutantStack& obj) {
			*this = obj; return (*this);
		};
		~MutantStack(void) {};

		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin(void) {
			return this->c.begin();
		}
		iterator end(void) {
			return this->c.end();
		}
		typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		const_iterator begin(void) const {
			return this->c.begin();
		}
		const_iterator end(void) const {
			return this->c.end();
		}
};
