/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:58:34 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/22 12:56:22 by kahmada          ###   ########.fr       */
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
