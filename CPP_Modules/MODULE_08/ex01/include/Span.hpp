#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <list>
#include <ctime>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;

		Span();
		//by making default constractor private
		//we are preventing the cration without N


	public:
		Span(unsigned int N);
		Span(Span const& rhs);
		Span& operator=(Span const& rhs);
		~Span();

		void	addNumber(int number);
		int		longestSpan() const;
		int		shortestSpan() const;

		//template member function: adding via iterator range
		template <typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end)
		{
			//calculate number of elemnts to be added
			std::size_t count = std::distance(begin, end);

			//capacity control
			if (_numbers.size() + count > _maxSize)
				throw SpanFullException();
			
			//adding numbers at once via std::vector::insert
			_numbers.insert(_numbers.end(), begin, end);
		}

		class SpanFullException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};


#endif