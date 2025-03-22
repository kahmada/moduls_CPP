#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form)
    : AForm(form), target(form.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
    {
        target = rhs.target;
    }
    return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSignStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    std::ofstream outfile;
    outfile.open(target + "_shrubbery");
    if (!outfile.is_open())
        throw std::runtime_error("Error: Could not create file");

    outfile << "      ccee88oo" << std::endl;
    outfile << "  C8O8O8Q8PoOb o8oo" << std::endl;
    outfile << " dOB69QO8yrsPdUOpugoO9bD" << std::endl;
    outfile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    outfile << " 6OuU  /p u gcoUodpP" << std::endl;
    outfile << "   \\LLL/  /douUP " << std::endl;
    outfile << "    ||||" << std::endl;
    outfile << "    ||||" << std::endl;
    outfile << "    ||||" << std::endl;

    outfile.close();
    std::cout << "File " << target << "_shrubbery created successfully!" << std::endl;
}

