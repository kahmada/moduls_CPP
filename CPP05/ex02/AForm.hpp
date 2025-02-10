#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
    std::string const name;
    bool isSigned;
    int const gradeToSign;
    int const gradeToExecute;

public:
    AForm();
    AForm(std::string const &name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &src);
    AForm &operator=(AForm const &rhs);
    virtual ~AForm() {}

    std::string const &getName() const;
    bool getSignStatus() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    virtual void execute(Bureaucrat const &executor) const = 0;

    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
