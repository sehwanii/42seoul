#pragma once

# include <iterator>
# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::out_of_range("Error: not found in container");
	return iter;
}
