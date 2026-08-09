#ifndef ITER_HPP
#define ITER_HPP

#include <cctype>
#include <iostream>
#include <string>

//T *arrray; allows us to support const nad non-const elemnts
template <typename T, typename Function>
void iter(T *array, const size_t arraylength, Function f)
{
	if (!array || !f)
		return;
	for (size_t i = 0; i < arraylength; i++)
	{
		f(array[i]);
	}
}

//read only functions should have T const&
template <typename T>
void print(T const &element)
{
	std::cout << element << "_";
}

//functions that changes the elemnt should be T&
template <typename T>
void decrement(T &element)
{
	element--;
}

template <typename T>
void increment(T &element)
{
	element++;
}


#endif