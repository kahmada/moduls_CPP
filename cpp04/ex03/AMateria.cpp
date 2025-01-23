/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:15:55 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/23 11:47:17 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(){}
AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const// erste: seiner return ist immer ct die zweite : kann nicht funktion ct wie konnen ncht etwas auf class anderes 
{
    return _type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria used at " << target.getName() << " *" << std::endl;
}
