#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;

    uintptr_t raw = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(raw);
    if (deserialized == &data) {
        std::cout << "Serialization and deserialization are successful!" << std::endl;
        std::cout << "Data ID: " << deserialized->id << ", Name: "  << std::endl;
    } else {
        std::cerr << "Error: Pointers do not match!" << std::endl;
    }

    return 0;
}
/*
Résumé :
Cet exercice vous apprend à convertir une adresse mémoire en une forme brute 
(un entier de type uintptr_t) et à la reconvertir en pointeur. Cela montre 
comment manipuler les adresses mémoire de manière sécurisée et permet de mieux 
comprendre les concepts de sérialisation/désérialisation, indispensables dans 
les systèmes complexes.
par exemple le pointeur contien l address memoire alors c est quelque chose en hexadecimal
donc on convert cette valeur hexa en decimal puis on deserialized alors si comme on le convertur 
en herxa a nouveau
*/