/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:30:41 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/04 17:30:42 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(Dog const &other);
	Dog	&operator=(Dog const &other);
    virtual void makeSound() const;
    ~Dog();
};

#endif // DOG_HPP

/*
Le polymorphisme en C++ permet aux objets de différentes classes d'être traités comme des objets d'une classe commune, tout en conservant leurs comportements spécifiques. Voici la différence clé :
Avec Animal (polymorphe) :
cppCopyclass Animal {
    virtual void makeSound() { ... }  // Fonction virtuelle
};

Le mot-clé virtual permet à chaque classe dérivée de redéfinir makeSound()
À l'exécution, c'est la version de la classe réelle de l'objet qui est appelée
Résultat : le chien aboie, le chat miaule

Avec WrongAnimal (non-polymorphe) :
cppCopyclass WrongAnimal {
    void makeSound() { ... }  // Fonction non virtuelle
};

Sans virtual, c'est toujours la version de la classe de base qui est appelée
Le type du pointeur détermine la fonction appelée, pas le type réel de l'objet
Résultat : tous les animaux font le même son générique

C'est pourquoi WrongCat->makeSound() produit le son de WrongAnimal, alors que cat->makeSound() produit bien un miaulement. CopyRetryClaude does not have the ability to run the code it generates yet.
*/