#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm(target, 145, 137) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSignStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outfile(getName() + "_shrubbery");
    if (outfile)
    {
        outfile << "ASCII Trees..." << std::endl;
        outfile.close();
    }
    else
    {
        std::cerr << "Error: Could not create file." << std::endl;
    }
}
