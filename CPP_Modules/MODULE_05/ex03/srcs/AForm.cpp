#include "../inc/AForm.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw AForm::GradeTooLowException();
    this->executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName() 
       << ", Status: " << (form.getIsSigned() ? "Signed" : "Unsigned") 
       << ", Sign Grade: " << form.getSignGrade() 
       << ", Exec Grade: " << form.getExecGrade();
    return os;
}