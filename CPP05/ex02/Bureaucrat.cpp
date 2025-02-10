#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "AForm.hpp"

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << getName() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}


Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : name(bureaucrat.getName())
{
	*this = bureaucrat;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->grade = rhs.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

std::string	const	&Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}


std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	return o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
}