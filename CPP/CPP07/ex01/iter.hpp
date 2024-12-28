#ifndef ITER_HPP
    #define ITER_HPP

#include <string>

template <typename T>
void iter(T *array, size_t len, void (*f)(T &)){
    if (array == NULL || f == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif