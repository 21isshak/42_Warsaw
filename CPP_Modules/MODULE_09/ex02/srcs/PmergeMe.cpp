#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isPositive(const std::string &str)
{
	if(str.empty())
		return false;

	for(size_t i = 0; i < str.length(); i++)
	{
		if(!std::isdigit(str[i]))
			return false;
	}

	long val = std::atol(str.c_str());
	return (val >= 0 && val <= 2147483647);
}

bool PmergeMe::parseArgs(int ac, char **av)
{
	for(int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		if(!isPositive(arg))
			return false;
		int num = std::atoi(arg.c_str());
		_vec.push_back(num);
		_deq.push_back(num);
	}
	return !_vec.empty();
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t size)
{
	std::vector<size_t> jacob;
	if (size == 0)
		return jacob;

	jacob.push_back(0);
	jacob.push_back(1);
	
	while(jacob.back() < size)
	{
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}
	return jacob;
}

void PmergeMe::sortVector(std::vector<int> &vec)
{
	size_t n = vec.size();
	if (n <= 1)
		return;

	// 1. creating pairs and sorting pairs
	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = (n % 2 != 0);

	for (size_t i = 0; i < n - (hasStraggler ? 1 : 0); i += 2)
	{
		int first = vec[i];
		int second = vec[i + 1];
		if (first < second)
			std::swap(first, second); // first is always the bigger one
		pairs.push_back(std::make_pair(first, second));
	}

	if (hasStraggler)
	{
		straggler = vec[n - 1];
	}

	// 2. creating vector to sort the big elemnts racursively
	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
	}

	sortVector(mainChain); //recursive call

	//rearrange the pairs according to mainChain to not lose the connection
	std::vector<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (mainChain[i] == pairs[j].first)
			{
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}

	//3. pending chain creation
	std::vector<int> pend;
	for (size_t i = 0; i < sortedPairs.size(); ++i)
	{
		pend.push_back(sortedPairs[i].second);
	}

	//first small elemt insertin directly to the top
	if (!pend.empty())
	{
		mainChain.insert(mainChain.begin(), pend[0]);
	}

	// 4. inserting via jacobsthal numbers(std::lower_bound)
	std::vector<size_t> jacob = generateJacobsthal(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	inserted[0] = true; //first already added

	for (size_t i = 1; i < jacob.size(); ++i)
	{
		size_t index = jacob[i];
		if (index >= pend.size())
			index = pend.size() - 1;

		for (size_t j = index; j > 0; --j)
		{
			if (!inserted[j])
			{
				int val = pend[j];
				std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
				mainChain.insert(it, val);
				inserted[j] = true;
            }
        }
    }

	//straggler element isertion(if exists)
	if (hasStraggler)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	vec = mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &deq)
{
	size_t n = deq.size();
	if (n <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = (n % 2 != 0);

	for (size_t i = 0; i < n - (hasStraggler ? 1 : 0); i += 2)
	{
		int first = deq[i];
		int second = deq[i + 1];
		if (first < second)
			std::swap(first, second);
		pairs.push_back(std::make_pair(first, second));
	}

	if (hasStraggler)
	{
		straggler = deq[n - 1];
	}

	std::deque<int> mainChain;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].first);
	}

	sortDeque(mainChain);

	std::deque<std::pair<int, int> > sortedPairs;
	for (size_t i = 0; i < mainChain.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (mainChain[i] == pairs[j].first)
			{
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}

	std::deque<int> pend;
	for (size_t i = 0; i < sortedPairs.size(); ++i)
	{
		pend.push_back(sortedPairs[i].second);
	}

	if (!pend.empty())
	{
		mainChain.push_front(pend[0]);
	}

	std::vector<size_t> jacob = generateJacobsthal(pend.size());
	std::vector<bool> inserted(pend.size(), false);
	inserted[0] = true;

	for (size_t i = 1; i < jacob.size(); ++i)
	{
		size_t index = jacob[i];
		if (index >= pend.size())
			index = pend.size() - 1;

		for (size_t j = index; j > 0; --j)
		{
			if (!inserted[j])
			{
				int val = pend[j];
				std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
				mainChain.insert(it, val);
				inserted[j] = true;
			}
		}
	}

	if (hasStraggler)
	{
		std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	deq = mainChain;
}

void PmergeMe::run()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << (i + 1 == _vec.size() ? "" : " ");
	}
	std::cout << std::endl;

	//vector time calculation
	struct timeval startVec;
	struct timeval endVec;
	gettimeofday(&startVec, NULL);
	sortVector(_vec);
	gettimeofday(&endVec, NULL);

	double vecTime = (endVec.tv_sec - startVec.tv_sec) * 1000000.0 + (endVec.tv_usec - startVec.tv_usec);

	//deque time calculation
	struct timeval startDeq;
	struct timeval endDeq;
	gettimeofday(&startDeq, NULL);
	sortDeque(_deq);
	gettimeofday(&endDeq, NULL);

	double deqTime = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0 + (endDeq.tv_usec - startDeq.tv_usec);

	std::cout << "After:  ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i] << (i + 1 == _vec.size() ? "" : " ");
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vecTime << " us" << std::endl;

	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque  : " << deqTime << " us" << std::endl;
}