#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm(std::string const &target);
    virtual void execute(Bureaucrat const &executor) const;
};

#endif
