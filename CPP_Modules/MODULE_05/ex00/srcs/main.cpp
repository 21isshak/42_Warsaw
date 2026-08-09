#include "../inc/Bureaucrat.hpp"

int main()
{
    std::cout << "\x1B[33m--- Test 1: Normal Creation and Increment/Decrement ---\033[0m" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 3);
        std::cout << bob << std::endl;
        
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Test 2: Grade Too High Exception at Init ---\033[0m" << std::endl;
    try
    {
        Bureaucrat high("Boss", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Test 3: Grade Too Low Exception at Init ---\033[0m" << std::endl;
    try
    {
        Bureaucrat low("Peon", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Test 4: Grade Too High via Increment ---\033[0m" << std::endl;
    try
    {
        Bureaucrat king("King", 1);
        std::cout << king << std::endl;
        king.incrementGrade(); // Should throw
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Test 5: Grade Too Low via Decrement ---\033[0m" << std::endl;
    try
    {
        Bureaucrat lazy("Lazy", 150);
        std::cout << lazy << std::endl;
        lazy.decrementGrade(); // Should throw
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    return 0;
}