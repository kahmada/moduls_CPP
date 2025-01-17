/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:56:48 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/14 15:42:52 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
Dog::Dog() {
    this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called!" << std::endl;
}
Dog::Dog(Dog const &other)
{
	this->brain = NULL;
	std::cout << "Dog copy constructor called!" << std::endl;
	*this = other;
}

Dog	&Dog::operator=(Dog const &other)
{
	delete this->brain;
	this->brain = new Brain(*other.brain);
	this->type = other.getType();
	return (*this);
}
Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "How! How!" << std::endl;
}