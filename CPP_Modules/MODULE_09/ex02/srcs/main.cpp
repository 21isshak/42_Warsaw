#include "../include/PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe pmergeme;
    if(!pmergeme.parseArgs(ac, av))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    pmergeme.run();
    return 0;
}