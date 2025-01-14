/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:19 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/02 10:16:39 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : value(0) {}

Fixed::Fixed(const int intValue)
{
    value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &ob)
{
    *this = ob;
}

Fixed &Fixed::operator=(const Fixed &ob)
{
    this->value = ob.getRawBits();
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)getRawBits() / (1 << this->fractionalBits));
}

int Fixed::toInt( void ) const
{
    return value >> fractionalBits;
}

bool Fixed::operator>(const Fixed &ob) const
{
    return value > ob.value;
}

bool Fixed::operator<(const Fixed &ob) const
{
    return value < ob.value;
}

bool Fixed::operator>=(const Fixed &ob) const
{
    return value >= ob.value;
}

bool Fixed::operator<=(const Fixed &ob) const
{
    return value <= ob.value;
}

bool Fixed::operator==(const Fixed &ob) const
{
    return value == ob.value;
}

bool Fixed::operator!=(const Fixed &ob) const
{
    return value != ob.value;
}

Fixed Fixed::operator+(const Fixed &ob) const
{
    Fixed result;              
    result.setRawBits(value + ob.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &ob) const
{
    Fixed result;
    result.setRawBits(value - ob.value);
    return result;
}

Fixed Fixed::operator*(const Fixed &ob) const
{
    Fixed result;
    result.setRawBits((value * ob.value) >> fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &ob) const
{
    Fixed result;
    result.setRawBits((value << fractionalBits) / ob.value);
    return result;
}

Fixed &Fixed::operator++(void)
{
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;                              
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--(void)
{
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}
