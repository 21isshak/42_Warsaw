#include "../inc/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
    return *this;
}

Intern::~Intern() {}

//helper static function to create Form
static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    //array of valid form names
    std::string formTypes[3] =
	{
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // array of function pointers
    AForm* (*formCreators[3])(const std::string&) =
	{
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    // control in loop to avoid an excessive if/elseif/else structure
    for (int i = 0; i < 3; i++)
	{
        if (formTypes[i] == formName)
		{
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target); //calling the matched function and returning form
        }
    }

    //if form not found
    std::cerr << "Error: Intern cannot create '" << formName << "' because it doesn't exist." << std::endl;
    return NULL;
}