#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cctype>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:

		Array() : _array(NULL), _size(0) {}

		Array(unsigned int n) : _size(n)
		{
			if (n == 0)
				_array = NULL;
			else
				_array = new T[n]();
		}
		
		Array(Array const &rhs)
		{
			_size = rhs._size;
			if (_size == 0)
				_array = NULL;
			else
			{
				_array = new T[_size]();
				for (unsigned int i = 0; i < _size; i++) _array[i] = rhs._array[i];
			}
		}


		~Array()
		{
			delete[] _array;
		};

		Array &operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete[] _array;
				_size = rhs._size;
				if (_size > 0)
				{
					_array = new T[_size]();
					for (unsigned int i = 0; i < _size; i++) _array[i] = rhs._array[i];
				}
				else
					_array = NULL;
			}
			return *this;
		}

		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw IndexOutOfRangeException();
			return _array[index];
		}

		T const &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw IndexOutOfRangeException();
			return _array[index];
		}

		unsigned int size() const { return _size; };

		class IndexOutOfRangeException : public std::exception {
			public:
				char const *what() const throw() { return "Index out of range!"; }
		};
};

#endif