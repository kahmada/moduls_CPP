#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm(target, 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
    : AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    if (this != &other)
    {
        *this = other;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSignStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "BZZZ... DRRR... VRRR..." << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << getName() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << getName() << "!" << std::endl;
}
