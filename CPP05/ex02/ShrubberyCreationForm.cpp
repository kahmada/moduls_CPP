#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm(target, 145, 137) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSignStatus())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();

    std::ofstream outfile((getName() + "_shrubbery").c_str());
    if (!outfile)
        throw std::runtime_error("Error: Could not create file " + getName() + "_shrubbery");

    outfile << "      _-_" << std::endl;
    outfile << "    /~~~~~~\\" << std::endl;
    outfile << " /~~ ~~~~~~ ~~\\" << std::endl;
    outfile << "{ ~~   ~~~~   ~~~ }" << std::endl;
    outfile << " \\  _- ~~  -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~ " << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;

    outfile.close();
}
