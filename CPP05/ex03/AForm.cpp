#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

std::string const &AForm::getName() const
{
    return this->name;
}

bool AForm::getSignStatus() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeToSign)
    {
        this->isSigned = true;
        std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
    }
    else
    {
        throw GradeTooLowException();
    }
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
    o << "Form " << rhs.getName()
      << ", Signed: " << (rhs.getSignStatus() ? "Yes" : "No")
      << ", Grade to Sign: " << rhs.getGradeToSign()
      << ", Grade to Execute: " << rhs.getGradeToExecute();
    return o;
}
