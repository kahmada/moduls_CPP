/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:41:12 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/02 10:15:00 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int value;                          
    static const int fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed& ob);
    Fixed& operator=(const Fixed& ob);
    ~Fixed();       

    int getRawBits( void ) const;                                
    void setRawBits(int const raw);      
};

#endif