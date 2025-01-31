#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm(target, 72, 45) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getSignStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << getName() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << getName() << "!" << std::endl;
}
