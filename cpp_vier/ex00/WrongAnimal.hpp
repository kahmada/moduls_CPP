/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:31:08 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/04 17:31:09 by kahmada          ###   ########.fr       */
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

#endif // WRONGANIMAL_HPP
