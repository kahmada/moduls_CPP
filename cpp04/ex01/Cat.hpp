/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:56:42 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/14 14:27:32 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain	*brain;
public:
    Cat();
    Cat(Cat const &other);
    Cat	&operator=(Cat const &other);
    virtual void makeSound() const;
    ~Cat();
};
#endif