/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:30:33 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/14 11:51:27 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}
Dog::Dog(Dog const &other)
{
	*this = other;
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog	&Dog::operator=(Dog const &other)
{
	this->type = other.type;
	return (*this);
}
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "HOW! HOW!" << std::endl;
}