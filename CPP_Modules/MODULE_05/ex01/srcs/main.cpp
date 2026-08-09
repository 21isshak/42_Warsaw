#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    std::cout << "\n\x1B[33m--- Test 1: Normal Form Creation & Signing ---\033[0m" << std::endl;
    try
	{
        Bureaucrat manager("Manager", 45);
        Form taxForm("Tax Form 28B", 50, 25);

        std::cout << manager << std::endl;
        std::cout << taxForm << std::endl;

        manager.signForm(taxForm);
        std::cout << "After attempt: " << taxForm << std::endl;
    }
	catch (std::exception &e)
	{
        std::cerr << "Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Test 2: Bureaucrat Grade Too Low to Sign ---\033[0m" << std::endl;
    try
	{
        Bureaucrat intern("Intern", 100);
        Form topSecretForm("Top Secret", 20, 5);

        std::cout << intern << std::endl;
        std::cout << topSecretForm << std::endl;

        intern.signForm(topSecretForm); // Intern'ün derecesi yetmemeli (100 > 20)
        std::cout << "After attempt: " << topSecretForm << std::endl;
    }
	catch (std::exception &e)
	{
        std::cerr << "Unexpected Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Test 3: Form Instantiation Exceptions ---\033[0m" << std::endl;
    try
	{
        std::cout << "Creating form with sign grade 0..." << std::endl;
        Form badForm("Bad", 0, 50);
    }
	catch (std::exception &e)
	{
        std::cerr << "Caught Form Exception: " << e.what() << std::endl;
    }

    try
	{
        std::cout << "\nCreating form with exec grade 151..." << std::endl;
        Form badForm2("Bad2", 50, 151);
    }
	catch (std::exception &e)
	{
        std::cerr << "Caught Form Exception: " << e.what() << std::endl;
    }

    return 0;
}