/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:56:59 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/14 20:19:54 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

static void	allocate(const Animal *animals[], int nb_animals)
{
	for (int i = 0; i < nb_animals; i++)
	{
		if (i < nb_animals / 2)
			animals[i] = new Dog();// creyit 2 dog o 2 cat dk chi bach constructor t3ayt lo joj mrat b nsba l kola whd
		else
			animals[i] = new Cat();
	}
}

static void	make_sound(const Animal *animals[], int nb_animals)
{
	for (int i = 0; i < nb_animals; i++)
		animals[i]->makeSound();
}

static void	deallocate(const Animal *animals[], int nb_animals)
{
	for (int i = 0; i < nb_animals; i++)
		delete animals[i];
}

int	main()
{
	const int		nb_animals = 4;
	const Animal	*animals[nb_animals];

	allocate(animals, nb_animals);
	make_sound(animals, nb_animals);
	deallocate(animals, nb_animals);
	// Dog basic;//Cette structure est utile pour tester le constructeur de copie et le destructeur de la classe Dog. ghir bach nnt2akdo bli canonical form khdama
	// {
	// 	Dog tmp = basic;
	// }
	return 0;
}
/*
when we remove  Dog basic;     {     Dog tmp = basic;     }
like we remove all that :

Animal constructor called
Brain constructor called!
Dog default constructor called!
Animal constructor called
Dog copy constructor called!
Brain copy constructor called! 
Brain destructor called!
Dog destructor called
Animal destructor called
Brain destructor called!
Dog destructor called
Animal destructor called
Analysons l'ordre des appels lors de la création et destruction des objets :

Pour Dog basic :


Constructeur Animal
Constructeur Brain
Constructeur Dog


Pour Dog tmp = basic :


Constructeur Animal
Constructeur copie Dog
Constructeur copie Brain


Fin du bloc {} = destruction de tmp :


Destructeur Brain
Destructeur Dog
Destructeur Animal


Fin du programme = destruction de basic :


Destructeur Brain
Destructeur Dog
Destructeur Animal

Cela montre l'ordre correct d'initialisation (de la base vers la dérivée) et de destruction (de la dérivée vers la base) des objets.
*/