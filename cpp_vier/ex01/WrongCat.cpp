/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:57:20 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/12 18:57:21 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called!" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	this->type = other.type;
	return (*this);
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "WrongAnimal makes a generic sound (not a cat's sound)" << std::endl;
}