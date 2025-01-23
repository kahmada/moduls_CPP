/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:16:31 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/22 17:16:32 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const & other) : AMateria(other._type) {}

Ice & Ice::operator=(Ice const & other) {
    if (this != &other)
        _type = other._type;
    return *this;
}

Ice::~Ice() {}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoot an ice bolt at " << target.getName() << " *" << std::endl;
}

