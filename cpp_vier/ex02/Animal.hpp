/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:57:40 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/12 18:57:41 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    
    Animal(Animal const &other);
    Animal	&operator=(Animal const &other);
    virtual void makeSound() const = 0;
    std::string getType() const;
    virtual ~Animal();
};

#endif // ANIMAL_HPP