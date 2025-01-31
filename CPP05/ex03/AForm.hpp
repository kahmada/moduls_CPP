#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

// Abstract base class
class Bureaucrat;
class AForm
{
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;

public:
    // Constructor and Destructor
    AForm(std::string const &name, int gradeToSign, int gradeToExecute);
    virtual ~AForm() {}

    // Getters
    std::string const &getName() const;
    bool getSignStatus() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Methods to be implemented by derived classes
    virtual void execute(Bureaucrat const &executor) const = 0;

    // Sign method
    void beSigned(Bureaucrat &bureaucrat);

    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw() { return "Grade is too high"; }
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw() { return "Grade is too low"; }
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw() { return "Form is not signed"; }
    };
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
