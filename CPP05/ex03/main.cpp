#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Intern.hpp"
#include "Bureaucrat.hpp" 

int main() {
    try {
        Intern someRandomIntern;
        AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat b1("bot", 50);

        b1.signForm(*rrf);
        b1.executeForm(*rrf);

        delete rrf;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

