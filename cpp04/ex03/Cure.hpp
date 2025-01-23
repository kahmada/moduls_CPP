/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:15:36 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/22 17:15:37 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria {
public:
    Cure();
    Cure(Cure const & other);
    Cure(AMateria const & amateria);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif

