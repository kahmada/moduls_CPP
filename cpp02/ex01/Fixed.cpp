/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:20:31 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/02 10:15:30 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &ob)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = ob;
}

int Fixed::getRawBits(void) const
{
    return value;
}

Fixed &Fixed::operator=(const Fixed &ob)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = ob.getRawBits();
    return *this;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = value * (1 << _fractionalBits);
}

Fixed::Fixed(float flot_value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(flot_value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
    return (float)value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return (value / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed& ob)
{
    out << ob.toFloat();
    return out;
}
