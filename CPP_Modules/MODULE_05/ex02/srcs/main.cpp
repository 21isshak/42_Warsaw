//MY
#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main() {
    std::cout << "\x1B[33m--- Testing ShrubberyCreationForm ---\033[0m" << std::endl;
    try
    {
        Bureaucrat john("John", 140); // Can sign, cannot execute
        ShrubberyCreationForm form1("garden");
        
        std::cout << john << std::endl;
        std::cout << form1 << std::endl;
        
        john.signForm(form1);
        john.executeForm(form1); // Should fail
        
        Bureaucrat boss("Boss", 100); // Can do both
        boss.executeForm(form1); // Should succeed
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Testing RobotomyRequestForm ---\033[0m" << std::endl;
    try
    {
        Bureaucrat bobby("Bobby", 40);
        RobotomyRequestForm form2("Claptrap");
        
        bobby.signForm(form2);
        bobby.executeForm(form2);
        bobby.executeForm(form2); // Execute again to see 50% chance
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Testing PresidentialPardonForm ---\033[0m" << std::endl;
    try
    {
        Bureaucrat prez("President", 3);
        PresidentialPardonForm form3("Arthur Dent");
        
        prez.signForm(form3);
        prez.executeForm(form3);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n\x1B[33m--- Testing Execution Without Signing ---\033[0m" << std::endl;
    try
    {
        Bureaucrat god("God", 1);
        PresidentialPardonForm form4("Marvin");
        
        god.executeForm(form4); // Should fail because unsigned
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

////AI
// #include "../inc/Bureaucrat.hpp"
// #include "../inc/ShrubberyCreationForm.hpp"
// #include "../inc/RobotomyRequestForm.hpp"
// #include "../inc/PresidentialPardonForm.hpp"

// void printTitle(const std::string& title) {
//     std::cout << "\n========================================\n";
//     std::cout << "  " << title << "\n";
//     std::cout << "========================================\n";
// }

// int main() {
//     // --- TEST 1: Bureaucrat limits and exceptions ---
//     printTitle("\x1B[33mTEST 1: Bureaucrat Instantiation Exceptions\033[0m");
//     try {
//         std::cout << "Attempting to create a Bureaucrat with grade 0..." << std::endl;
//         Bureaucrat invalidHigh("TooHigh", 0);
//     } catch (std::exception& e) {
//         std::cerr << "Caught Exception: " << e.what() << std::endl;
//     }

//     try {
//         std::cout << "\nAttempting to create a Bureaucrat with grade 151..." << std::endl;
//         Bureaucrat invalidLow("TooLow", 151);
//     } catch (std::exception& e) {
//         std::cerr << "Caught Exception: " << e.what() << std::endl;
//     }


//     // --- TEST 2: Shrubbery creation form (Sign: 145, Execute: 137) ---
//     printTitle("\x1B[33mTEST 2: ShrubberyCreationForm Execution Flow\033[0m");
//     try {
//         Bureaucrat lowStaff("LowStaff", 146);
//         Bureaucrat midStaff("MidStaff", 140);
//         Bureaucrat highStaff("HighStaff", 135);
//         ShrubberyCreationForm shrubForm("garden");

//         std::cout << shrubForm << std::endl;

//         // not able to sign buraucrat
//         std::cout << "\n-> " << lowStaff.getName() << " tries to sign..." << std::endl;
//         lowStaff.signForm(shrubForm);

//         // able to sign but can not execute buraucrat
//         std::cout << "\n-> " << midStaff.getName() << " tries to sign and execute..." << std::endl;
//         midStaff.signForm(shrubForm);
//         midStaff.executeForm(shrubForm); // Çalıştırma hatası fırlatmalı (140 > 137)

//         // able to sign and execute buraucrat
//         std::cout << "\n-> " << highStaff.getName() << " tries to execute..." << std::endl;
//         highStaff.executeForm(shrubForm); // most be succesfull and create garden_shruberry
//     } catch (std::exception& e) {
//         std::cerr << "Unexpected Global Exception in Test 2: " << e.what() << std::endl;
//     }


//     // --- TEST 3: robotomy request form (sign: 72, execute: 45) ---
//     printTitle("\x1B[33mTEST 3: RobotomyRequestForm (50% Success/Failure Rate)\033[0m");
//     try {
//         Bureaucrat specialist("Specialist", 43);
//         RobotomyRequestForm robotForm("Bender");

//         specialist.signForm(robotForm);
        
//         // to see %50 cance factor call 4 times in a row
//         std::cout << "\nExecuting multiple times to test randomness:" << std::endl;
//         specialist.executeForm(robotForm);
//         specialist.executeForm(robotForm);
//         specialist.executeForm(robotForm);
//         specialist.executeForm(robotForm);
//     } catch (std::exception& e) {
//         std::cerr << "Unexpected Global Exception in Test 3: " << e.what() << std::endl;
//     }


//     // --- TEST 4: PRESIDENTIAL PARDON FORM (İmza: 25, Çalıştırma: 5) ---
//     printTitle("\x1B[33mTEST 4: PresidentialPardonForm Flow\033[0m");
//     try {
//         Bureaucrat minister("Minister", 20);
//         Bureaucrat president("President", 2);
//         PresidentialPardonForm pardonForm("Arthur Dent");

//         // İmzasız formu çalıştırmayı denemek
//         std::cout << "-> Tries to execute unsigned form:" << std::endl;
//         president.executeForm(pardonForm); 

//         // İmzalama ve yetersiz çalıştırma derecesi
//         std::cout << "\n-> Minister signs but tries to execute:" << std::endl;
//         minister.signForm(pardonForm);
//         minister.executeForm(pardonForm); // Derecesi yetmemeli (20 > 5)

//         // Cumhurbaşkanı çalıştırır
//         std::cout << "\n-> President tries to execute:" << std::endl;
//         president.executeForm(pardonForm); // Başarılı olmalı
//     } catch (std::exception& e) {
//         std::cerr << "Unexpected Global Exception in Test 4: " << e.what() << std::endl;
//     }


//     // --- TEST 5: ORTHODOX CANONICAL FORM DOĞRULAMA (Copy & Assignment) ---
//     printTitle("\x1B[33mTEST 5: Copy Constructor & Assignment Operator Check\033[0m");
//     try {
//         Bureaucrat boss("The Big Boss", 1);
//         RobotomyRequestForm originalForm("TargetA");
        
//         boss.signForm(originalForm);

//         // Copy Constructor Testi
//         std::cout << "\nCreating a copy of the signed form using Copy Constructor..." << std::endl;
//         RobotomyRequestForm copiedForm(originalForm);
//         std::cout << "Original Form Signed Status: " << (originalForm.getIsSigned() ? "Yes" : "No") << std::endl;
//         std::cout << "Copied Form Signed Status:   " << (copiedForm.getIsSigned() ? "Yes" : "No") << std::endl;

//         // Assignment Operator Testi
//         std::cout << "\nTesting Assignment Operator..." << std::endl;
//         RobotomyRequestForm assignedForm("TargetB");
//         std::cout << "Assigned Form Status (Before): " << (assignedForm.getIsSigned() ? "Yes" : "No") << std::endl;
//         assignedForm = originalForm;
//         std::cout << "Assigned Form Status (After):  " << (assignedForm.getIsSigned() ? "Yes" : "No") << std::endl;

//         std::cout << "\nExecuting the copied form:" << std::endl;
//         boss.executeForm(copiedForm);
//     } catch (std::exception& e) {
//         std::cerr << "Exception in Test 5: " << e.what() << std::endl;
//     }

//     printTitle("\x1B[34mALL TESTS COMPLETED SUCCESSFULLY\033[0m");
//     return 0;
// }