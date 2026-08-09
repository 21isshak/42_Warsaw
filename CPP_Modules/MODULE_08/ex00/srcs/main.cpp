#include "../include/easyfind.hpp"

const char* ElementNotFound::what() const throw()
{
	return ("No occurrence of element is found!");
}

int main()
{
	std::vector<int> vec;//dynamic array(an array that not sizes is not know)
	vec.push_back(1);
	vec.push_back(8);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(7);
	vec.push_back(9);

	try
	{
		std::vector<int>::iterator iter = easyfind(vec, 7);
		std::cout << "Value " << *iter << " found at location " << std::distance(vec.begin(), iter) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator iter = easyfind(vec, 5);
		std::cout << "Value " << *iter << " found at location " << std::distance(vec.begin(), iter) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
