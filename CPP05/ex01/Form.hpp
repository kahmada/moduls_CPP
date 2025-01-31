#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
private:
    std::string const name;
    bool issigned;
    int const gradesigne;
    int const gradeexecute;

public:
    Form(std::string const name, int const gradeToSign, int const gradeToExecute);
    Form(Form const &form);
    Form &operator=(Form const &rhs);
    ~Form();

    std::string const &getName() const;
    bool getSignStatus() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FormAlreadySignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
