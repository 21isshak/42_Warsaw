#include "../include/iter.hpp"

void Capitalize(std::string& str)
{
	for (unsigned int i = 0; i < str.size(); i++)
	{
		str.at(i) = std::toupper(str.at(i));
	}
}

class Clas
{
	public:
		Clas(void) : _n(42) { return; }
		int get(void) const { return this->_n; }

	private:
		int _n;
};

std::ostream& operator<<(std::ostream& o, Clas const& rhs)
{
	o << rhs.get();
	return o;
}


int main()
{

	int tab[] = {0, 1, 2, 3, 4};

	Clas tab2[5];

	const int size = 11;
	int array[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::string strs[2] = {"hello", "world"};

	const int fixed_array[] = {1, 2, 3};

	iter(tab, 5, print<const int>);
	std::cout << std::endl;

	iter(tab2, 5, print<Clas>);
	std::cout << std::endl;

	iter(array, size, print<int>);
	std::cout << std::endl;

	iter(array, size, increment<int>);
	iter(array, size, print<int>);
	std::cout << std::endl;

	iter(array, size, decrement<int>);
	iter(array, size, print<int>);
	std::cout << std::endl;

	iter(strs, 2, print<std::string>);
	std::cout << std::endl;

	iter(strs, 2, Capitalize);
	iter(strs, 2, print<std::string>);
	std::cout << std::endl;

	iter(fixed_array, 3, print<int>);//works thanks to T const& in 'print'
	std::cout << std::endl;

	//iter(fixed_array, 3, increment<int>);//this is error because fixed_array is const



	return 0;
}
