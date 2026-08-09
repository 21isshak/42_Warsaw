#include "../include/Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(Span const& rhs)
{
	*this = rhs;
}

Span &Span::operator=(Span const& rhs)
{
	if (this != &rhs)
	{
		_numbers = rhs._numbers;
		_maxSize = rhs._maxSize;
	}
	return *this;
}

Span::~Span() {};


void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(number);
}

int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw NoSpanException();
	
	int min_val = *std::min_element(_numbers.begin(), _numbers.end());
	int max_val = *std::max_element(_numbers.begin(), _numbers.end());

	return (max_val - min_val);
}

int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw NoSpanException();

	std::vector<int> sorted_numbers = _numbers;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	int minSpan = sorted_numbers[1] - sorted_numbers[0];
	int diff;
	
	for (size_t i = 1; i < sorted_numbers.size(); i++)
	{
		diff = sorted_numbers[i] - sorted_numbers[i - 1];
		if(diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

const char* Span::NoSpanException::what() const throw()
{
	return "Not enough elements to span!";
}

const char* Span::SpanFullException::what() const throw()
{
	return"Span is full!";
}
