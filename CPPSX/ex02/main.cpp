#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



Base* generate() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random = std::rand() % 3; //si on remove %3 le type douvien c

    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Type: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Type: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Type: C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}


void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type: B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type: C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Unknown type" << std::endl;
}

int main()
{
    Base* base = generate();
    std::cout << "Identification via Base*:" << std::endl;
    identify(base);

    std::cout << "Identification via Base&:" << std::endl;
    identify(*base);

    delete base;

    return 0;
}
/*
Étapes expliquées avec un exemple concret
Définir une classe de base et des classes dérivées :

Base : représente un "objet graphique générique".
A, B, C : des formes spécifiques (cercle, rectangle, triangle).
Créer une fonction generate() :

Cette fonction crée aléatoirement un objet de type A, B ou C et retourne un pointeur de type Base.
Exemple : Votre programme décide de générer un "cercle" (A), mais vous ne le savez pas encore car il retourne un Base*.

Identifier dynamiquement le type :

Avec identify(Base* p) : en passant un pointeur vers l'objet.
Avec identify(Base& p) : en passant une référence vers l'objet (sans utiliser de pointeur).
Vous utilisez dynamic_cast pour tester si l'objet est un cercle, un rectangle ou un triangle.
*/
/*
Résumé du fonctionnement global
generate() crée un objet de type aléatoire parmi A, B, ou C et retourne un pointeur de type Base*.
identify(Base* p) utilise un pointeur pour identifier dynamiquement le type réel de l'objet.
identify(Base& p) utilise une référence pour identifier dynamiquement le type réel de l'objet.
main() vérifie que ces fonctions fonctionnent correctement.
Cet exercice met en pratique le polymorphisme, les conversions dynamiques avec dynamic_cast, et l'identification des types réels en C++.
*/