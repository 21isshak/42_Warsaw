#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

//declaration and implementetion of templates should be in header fyle
template <typename T>
void swap(T& t1, T& t2)
{
	T tmp;

	tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template <typename T>
T const& max(T const& t1, T const& t2)
{
	//ternary operator
	return (t1 > t2) ? t1 : t2;
	// //if/else
	// if (t1 > t2)
	// 	return t1;
	// else
	// 	return t2;
}

template <typename T>
T const& min(T const& t1, T const& t2)
{
	return (t1 < t2) ? t1 : t2;
}

#endif