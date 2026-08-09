#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

class ElementNotFound : public std::exception
{
	public:
		const char* what() const throw();
};

//std::find: a function in <algorithm> that searchs
//it has to take the start point[begin()] and the last point[end()] of the container for searching
//iterator is type that name
template <typename T>
typename T::iterator easyfind(T& container, int value_to_find)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), value_to_find);
	if (iter == container.end())
		throw ElementNotFound();
	return iter;
}

#endif