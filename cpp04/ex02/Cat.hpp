/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:58:01 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/12 18:58:02 by kahmada          ###   ########.fr       */
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
    void makeSound() const;
    ~Cat();
};
#endif