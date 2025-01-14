/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:20:37 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/02 10:15:42 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value;
    static const int _fractionalBits = 8;

public:
    Fixed(void);
    Fixed(int value);
    Fixed(float flot_value);
    Fixed(const Fixed &ob);
    ~Fixed();

    Fixed& operator= (const Fixed &ob);
    int getRawBits( void ) const;
    float toFloat(void) const;
    int toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed& ob);
#endif
