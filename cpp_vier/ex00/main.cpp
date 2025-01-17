/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:29:39 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/04 17:33:31 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal* animal = new Animal();//Animal constructor called
	Animal* dog = new Dog();//Animal constructor called   Dog constructor called
	Animal* cat = new Cat();//Animal constructor called Cat constructor called
	WrongAnimal* wrongAnimal = new WrongAnimal();//WrongAnimal constructor called
	WrongAnimal* wrongCat = new WrongCat();//WrongAnimal constructor called WrongCat constructor called
	std::cout << cat->getType() << " " << std::endl;//cat
	std::cout << dog->getType() << " " << std::endl;//dog
	cat->makeSound();//mew
	dog->makeSound();///woof
	animal->makeSound();//Animal makes a generic sound
	wrongAnimal->makeSound();//WrongAnimal makes a generic sound
	wrongCat->makeSound();//WrongAnimal makes a generic sound
	delete animal;//Animal destructor called //Animal destructor called
	delete dog;//Dog destructor called  //Animal destructor called
	delete cat;//Cat destructor called //Animal destructor called
	delete wrongAnimal;//WrongAnimal destructor called
	delete wrongCat;//WrongAnimal destructor called // WrongAnimal destructor called
	return 0;
}

/*
Je vais expliquer la séquence de sortie :

Les constructeurs :


Le constructeur Animal est appelé 3 fois (pour animal, dog, cat)
Les constructeurs des classes dérivées (Dog, Cat) sont appelés après leur constructeur de base
Même chose pour la hiérarchie WrongAnimal


L'appel des méthodes :


getType() retourne "Cat" et "Dog" pour les objets respectifs
makeSound() montre un comportement polymorphe pour la hiérarchie Animal (sons différents)
La hiérarchie WrongAnimal montre un comportement non-polymorphe (même son générique)

La différence principale : Animal utilise des fonctions virtuelles (polymorphisme), contrairement à WrongAnimal. 
C'est pourquoi on obtient des sons différents avec Animal mais le même son générique avec WrongAnimal.

Les destructeurs :


Les destructeurs des classes dérivées sont appelés en premier
Suivis des destructeurs des classes de base
*/