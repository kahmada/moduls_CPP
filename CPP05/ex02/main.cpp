#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Bot", 50);
        ShrubberyCreationForm sForm("Home");
        RobotomyRequestForm rForm("Target1");
        PresidentialPardonForm pForm("Target2");

        b1.signForm(sForm);
        b1.signForm(rForm);
        b1.signForm(pForm);

        b1.executeForm(sForm);
        b1.executeForm(rForm);
        b1.executeForm(pForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
