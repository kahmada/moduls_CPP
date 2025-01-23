/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahmada <kahmada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:58:17 by kahmada           #+#    #+#             */
/*   Updated: 2025/01/22 12:56:01 by kahmada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

static void alocate_and_dealocate(const Animal *animals[], int nb_animals)
{
    for (int i = 0; i < nb_animals; i++)
	{
        if (i < nb_animals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < nb_animals; i++)
	{
        animals[i]->makeSound();
    }
    for (int i = 0; i < nb_animals; i++)
	{
        delete animals[i];
    }
}

int main()
{
    const int nb_animals = 4;
    const Animal *animals[nb_animals];
	Dog dog;
    Dog b(dog);
    Dog c;
    c = dog;
    alocate_and_dealocate(animals, nb_animals);
    return 0;
}
