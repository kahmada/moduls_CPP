#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm
{
    private:
        std::string target; 
    public:

        RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const &other);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        void execute(Bureaucrat const &executor) const;
};

#endif
