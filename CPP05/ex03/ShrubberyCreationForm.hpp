#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target; 

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;
    std::string const &getTarget() const;
};

#endif