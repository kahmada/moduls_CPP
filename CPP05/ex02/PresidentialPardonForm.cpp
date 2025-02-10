#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm(target, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
    : AForm(other) {}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if (this != &other)
    {
        *this = other;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getSignStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
