/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:30:14 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/04 17:30:15 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}
Cat::Cat(Cat const &cat)
{
	*this = cat;
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat	&Cat::operator=(Cat const &other)
{
	this->type = other.type;
	return (*this);
}
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}