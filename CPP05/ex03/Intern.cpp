#include "Intern.hpp"

// Constructors & Destructor
Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &rhs) {
    (void)rhs; // No specific assignment logic, as Intern has no state
    return *this;
}

Intern::~Intern() {}

// Method to create forms
AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    AForm *form = nullptr;

    if (formName == "shrubbery creation")
        form = new ShrubberyCreationForm(target);
    else if (formName == "robotomy request")
        form = new RobotomyRequestForm(target);
    else if (formName == "presidential pardon")
        form = new PresidentialPardonForm(target);
    else
        throw UnknownFormException();

    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}

// Exception for unknown form name
const char *Intern::UnknownFormException::what() const throw() {
    return "Unknown form type!";
}



















































