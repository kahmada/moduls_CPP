/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:58:11 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/22 12:55:50 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain	*brain;
public:
    Dog();
    Dog(Dog const &other);
	Dog	&operator=(Dog const &other); 
    void makeSound() const;
    ~Dog();
};

#endif