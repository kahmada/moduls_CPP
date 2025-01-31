#include "Bureaucrat.hpp"
#include "Form.hpp"


void Bureaucrat::signForm(Form &form)// 
{
    try
    {
        form.beSigned(*this);  // This calls the Form's beSigned method
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
//il entre au beSigned il vois si le form a deja signe ou bien le grade n est pas sufisant si ca il retre au catch pour faire l execption 
Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
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


std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	return o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
}