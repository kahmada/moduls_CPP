/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:56:54 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/20 15:42:43 by kahmada          ###   ########.fr       */
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
    virtual void makeSound() const;
    ~Dog();
};

#endif