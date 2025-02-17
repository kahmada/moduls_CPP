#include "Form.hpp"

Form::Form()
    : name("default"), issigned(false), gradesigne(150), gradeexecute(150)
{
}
Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute)
    : name(name), issigned(false), gradesigne(gradeToSign), gradeexecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &form)
    : name(form.name), issigned(form.issigned), gradesigne(form.gradesigne), gradeexecute(form.gradeexecute)
{
}

Form &Form::operator=(Form const &rhs)
{
    if (this != &rhs)
    {
        this->issigned = rhs.issigned;
    }
    return *this;
}

Form::~Form() {}

std::string const &Form::getName() const
{
    return this->name;
}

bool Form::getSignStatus() const
{
    return this->issigned;
}

int Form::getGradeToSign() const
{
    return this->gradesigne;
}

int Form::getGradeToExecute() const
{
    return this->gradeexecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (this->issigned)
        throw FormAlreadySignedException();

    if (bureaucrat.getGrade() > this->gradesigne)
        throw GradeTooLowException();
    
    this->issigned = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low!";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high!";
}

const char *Form::FormAlreadySignedException::what() const throw()
{
    return "Form is already signed!";
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
    o << rhs.getName() << ", sign status: " << (rhs.getSignStatus() ? "signed" : "not signed")
      << ", required grade to sign: " << rhs.getGradeToSign()
      << ", required grade to execute: " << rhs.getGradeToExecute();
    return o;
}
