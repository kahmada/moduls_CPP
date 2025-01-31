// #pragma once

// #include <iostream>
// #include <stdexcept>

// class	Form;
// class	AForm;
// class Bureaucrat
// {
// private:
//     std::string const	name;
//     int					grade;
// public:
// 	void executeForm(AForm const &form);
//     void signForm(Form &form);
// 	std::string const	&getName() const;
// 	int					getGrade() const;
// 	void				incrementGrade();
// 	void				decrementGrade();

// 	Bureaucrat();
// 	Bureaucrat(std::string const name, int grade);
// 	Bureaucrat(Bureaucrat const &bureaucrat);
// 	Bureaucrat	&operator=(Bureaucrat const &rhs);
// 	~Bureaucrat();

// 	class GradeTooLowException : public std::exception
// 	{
// 		public:
// 			const char* what() const throw();
// 	};
// 	class GradeTooHighException : public std::exception
// 	{
// 		public:
// 			const char* what() const throw();
// 	};
// };

// std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);
// Bureaucrat.hpp

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"  // Include the correct AForm header

class AForm;
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
	void executeForm(AForm const &form);
    void signForm(AForm &form); // Update here to accept AForm, not Form.

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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
