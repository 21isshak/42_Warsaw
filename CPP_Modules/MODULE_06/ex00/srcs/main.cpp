#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "Wrong Number Of Arguments Passed" << std::endl;
		return 0;
	}

	try
	{
		std::string input(argv[1]);
		ScalarConverter::convert(input);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error " << e.what() << std::endl;
	}

	return 0;
}