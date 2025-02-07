#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)// darum es ist const (name) und darum wir konnen nicht mache es innen die funcktion
{
    if (grade > 150)
        throw GradeTooLowException();//fur einen exeption rufen an
    if (grade < 1)
        throw GradeTooHighException();// die selbst zuschtand
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name){ //wir konnen machen es im initailis list
    this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
    {
        this->grade = rhs.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()// das beteuted dass wir konnen nicht einen exption trow inen die exeption
{
    return "Grade too high!";
}

std::string const &Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->grade <= 1)
        throw GradeTooHighException();
    --this->grade;
}

void Bureaucrat::decrementGrade()
{
     if (this->grade >= 150)
        throw GradeTooLowException();
    ++this->grade;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}





// try
// {
//     // Code qui peut lever une exception
// }
// catch (const std::exception &e)
// {
//     // Gestion de l'exception
// }