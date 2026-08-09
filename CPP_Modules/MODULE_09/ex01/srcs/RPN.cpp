#include "../include/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &rhs)
{
	*this = rhs;
}

RPN& RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool RPN::makeOperation(char op)
{
	if(_stack.size() < 2)
		return false;

	double b = _stack.top();
	_stack.pop();

	double a = _stack.top();
	_stack.pop();
	
	if(op == '+')
		_stack.push(a + b);
	else if(op == '-')
		_stack.push(a - b);
	else if(op == '/')
	{
		if(b == 0)
			return false;
		_stack.push(a / b);
	}
	else if(op == '*')
		_stack.push(a * b);

	return true;
}

void RPN::calculate(const std::string &expression)
{
	for(size_t i = 0; i < expression.length(); i++)
	{
		char c = expression[i];

		if(c == ' ')
			continue;

		if(c >= '0' && c <= '9')
			_stack.push(c - '0');
		else if(isOperator(c))
		{
			if(!makeOperation(c))
			{
				std::cerr << "Error" << std::endl;
				return;
			}
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return;
		}
	}

	if(_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		std::cerr << "Error" << std::endl;

}