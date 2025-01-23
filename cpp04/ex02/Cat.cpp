/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:57:57 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/22 12:55:32 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called!" << std::endl;
}
Cat::Cat(Cat const &other)
{
	this->brain = NULL;
	*this = other;
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat	&Cat::operator=(Cat const &other)
{
	delete this->brain;
	this->brain = new Brain(*other.brain);
	this->type = other.getType();
	return (*this);
}
Cat::~Cat()
{
    delete this->brain;
	std::cout << "Cat destructor called!" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}