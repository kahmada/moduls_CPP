/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:57:15 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/20 15:42:37 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(WrongAnimal const &other);
	WrongAnimal	&operator=(WrongAnimal const &other);
    void makeSound() const;
    std::string getType() const;
    virtual ~WrongAnimal();
};

#endif
