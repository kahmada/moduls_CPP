#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
    std::string const	name;
    int					grade;
public:
	std::string const	&getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const &bureaucrat);
	Bureaucrat	&operator=(Bureaucrat const &rhs);
	~Bureaucrat();

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
