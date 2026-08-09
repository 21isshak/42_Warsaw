#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <cstdlib>
#include <sys/time.h>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		std::vector<size_t> generateJacobsthal(size_t size);

		void sortVector(std::vector<int> &vec);
		void sortDeque(std::deque<int> &deq);

		bool isPositive(const std::string &str);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe();

		bool parseArgs(int ac, char **av);
		void run();
};

#endif