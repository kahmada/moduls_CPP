/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:16:29 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/02 10:16:50 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int value;
    static const int fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const int intValue);
    Fixed(const float floatValue);
    Fixed(const Fixed &ob);
    Fixed &operator=(const Fixed &ob);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(const Fixed &ob) const;

    bool operator<(const Fixed &ob) const;
    bool operator>=(const Fixed &ob) const;
    bool operator<=(const Fixed &ob) const;
    bool operator==(const Fixed &ob) const;
    bool operator!=(const Fixed &ob) const;

    Fixed operator+(const Fixed &ob) const;
    Fixed operator-(const Fixed &ob) const;
    Fixed operator*(const Fixed &ob) const;
    Fixed operator/(const Fixed &ob) const;

    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
