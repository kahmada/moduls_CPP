#pragma once

#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iostream>
template <typename T>//cette fonction retourn un pointeur vers la position de value sa veut dire l adress memoir de value et apres en afiche *it
typename T::iterator easyfind(T &container, int value)//Cela indique explicitement que T::iterator est un type et non une valeur
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found");//Si it est égal à container.end(), cela signifie que std::find() n'a pas trouvé l’élément dans le conteneur.
    return it;
}
//Lorsqu'on utilise un template T, le compilateur ne sait pas immédiatement si T::iterator est un type ou une valeur.
//typename lève cette ambiguïté et indique qu'il s'agit bien d'un type.
//Si T est un std::vector<int>, alors :
//T::iterator  →  std::vector<int>::iterator
//Si T est un std::list<int>, alors :
//T::iterator  →  std::list<int>::iterator



