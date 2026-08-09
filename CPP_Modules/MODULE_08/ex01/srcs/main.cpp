#include "../include/Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp1(10);
	std::vector<int> vec;
	
	sp1.addNumbers(vec.begin(), vec.end());

	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);



	try
    {
        unsigned int size = 15000;
        Span bigSpan(size);

        //a temp vector that is gong to be used for random 15000 creation
        std::vector<int> random_numbers;
        std::srand(std::time(NULL));

        for (unsigned int i = 0; i < size; ++i)
            random_numbers.push_back(std::rand());

        bigSpan.addNumbers(random_numbers.begin(), random_numbers.end());

        std::cout << "15000 elements added." << std::endl;
        std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest Span: "  << bigSpan.longestSpan()  << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

	//since we have addNumbers template
	//we are able to run it even with different type of containers
	//std::vector std::list
	Span sp2(5);
    std::list<int> list;

    list.push_back(5);
    list.push_back(15);
    list.push_back(19);
    list.push_back(8);

	sp2.addNumbers(list.begin(), list.end());

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	//even with array
	Span sp3(4);
	int arr[] = {3, 6, 8, 9};

	sp3.addNumbers(arr, arr + 4);
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;
	
	return 0;
}
