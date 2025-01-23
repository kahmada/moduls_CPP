/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:29:57 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/22 12:43:46 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}
Animal::Animal(Animal const &animal)
{
	*this = animal;
	std::cout << "Animal copy constructor called!" << std::endl;
}
Animal	&Animal::operator=(Animal const &rhs)
{
	this->type = rhs.getType();
	return (*this);
}
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const {
    return type;
}
