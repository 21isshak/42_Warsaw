#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("The Big Boss", 1);
    AForm* rrf;

    std::cout << "\x1B[33m--- Test 1: Creating Robotomy Request (Valid) ---\033[0m" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; //preventing memory leak by deleting new'ed object
    }

    std::cout << "\n\x1B[33m--- Test 2: Creating Shrubbery Creation (Valid) ---\033[0m" << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (rrf)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n\x1B[33m--- Test 3: Creating Presidential Pardon (Valid) ---\033[0m" << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (rrf)
    {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n\x1B[33m--- Test 4: Creating Invalid Form (Should Fail Elegantly) ---\033[0m" << std::endl;
    rrf = someRandomIntern.makeForm("coffee request", "Intern");
    if (rrf)
    {
        //if structure was wrong it would enter here and deleted
        delete rrf;
    }
    else
    {
        std::cout << "Form creation failed as expected, rrf is NULL." << std::endl;
    }

    return 0;
}