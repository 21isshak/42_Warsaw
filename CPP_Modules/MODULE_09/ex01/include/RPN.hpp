#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
    private:
        std::stack<double> _stack;

		bool isOperator(char c) const;
		bool makeOperation(char op);

	public:
		RPN();
		RPN(const RPN &rhs);
		RPN &operator=(const RPN &rhs);
		~RPN();

		void calculate(const std::string &expression);
};

#endif