#include "../inc/Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade) 
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
	{
        _isSigned = other._isSigned;
        // const variables can not be assigned, so _isSigned just being updated.
    }
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _isSigned = true;
}
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form [Name: " << form.getName() 
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") 
       << ", Sign Grade required: " << form.getSignGrade() 
       << ", Exec Grade required: " << form.getExecGrade() << "]";
    return os;
}