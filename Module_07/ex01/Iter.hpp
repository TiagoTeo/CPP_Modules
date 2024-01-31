#ifndef ITER_HPP
#define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
void printElememts(T &t)
{
	std::cout << t << " ";
}

template <typename T>
void iter(T	*arr, std::size_t len, void (*func)(T &t))
{
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif